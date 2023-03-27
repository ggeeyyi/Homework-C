//用户定义函数，可以根据需要自行添加或修改
/******************************************************************************/
/*----------------------------------引用---------------------------------------*/
/******************************************************************************/
#include "UserSource.h"
#include "stdio.h"
#include "stdlib.h"
/******************************************************************************/
/*---------------------------------用户变量定义-----------------------------------*/
/******************************************************************************/
uint8 ctldata = 0;
int CodePerid;      //编码器瞬时码率(对应瞬时速度)
float distance,value;     //超声波距离(毫米)
int myduty=0;       //马达参数
int myangle=0;      //舵机参数
int threshold = 80; //二值化阈值
int sign=0;
#define A 10

#define KP 1.0  // 比例系数
#define KI 0.1  // 积分系数
#define KD 0.2  // 微分系数
#define thresholdFordegreeOfSteering 1000
#define CodePeridIndex 0.0 //待修正的参数——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
struct _pid{
    float SetSpeed;            //定义设定值
    float ActualSpeed;        //定义实际值
    float err;                //定义偏差值
    float err_last;            //定义上一个偏差值
    float Kp,Ki,Kd;            //定义比例、积分、微分系数
    float voltage;          //定义速度值（控制执行器的变量）
    float integral;            //定义积分值
}pid;

///******************************************************************************/
///*----------------------------------用户函数------------------------------------*/
///******************************************************************************/
////函数及函数用法
//样例用户自身电机函数
void motor_duty(int duty)
{
    if (duty > 0)
        SetMotor(FORWARD, duty);
    else
        SetMotor(BACKWARD, -duty);
}
//样例用户自身舵机函数
void steer_angle(int duty) {
    if (duty > 0)
        SetSteer(LEFT, duty);
    else if (duty < 0)
        SetSteer(RIGHT, -duty);
    else
        SetSteer(MIDDLE, duty);
}
//样例用户通过串口（蓝牙或USB->TTL）发送一个整数
void dutyTrans(int duty) {
    if (duty == 0){
        Bluetooth_Send_Data('0');
    }
    else if (duty < 0){
        Bluetooth_Send_Data('-');
        duty=abs(duty);
    }
    //简单的栈，限制数字最多20位（10进制，包括标点符号）
    int stack[20];
    int stackP = 0;
    while(duty){
        stack[stackP++] = duty % 10;
        duty /= 10;
    }
    stackP--;
    while(stackP >= 0){
        Bluetooth_Send_Data((char)stack[stackP--] + '0');
    }
    //根据需要自行分隔
    //Bluetooth_Send_Data(' ');
}
//样例串口发送陀螺仪状态函数，适配SerialChart格式
void sendMPU6050Data(void){
    dutyTrans(Yaw);
    Bluetooth_Send_Data(',');
    dutyTrans(Pitch);
    Bluetooth_Send_Data(',');
    dutyTrans(Roll);
    Bluetooth_Send_Data('\n');
}
void MPU6050debug(void){
    dutyTrans(Yaw);
    Bluetooth_Send_Data(',');
    dutyTrans(Offset);
    Bluetooth_Send_Data(',');
    dutyTrans(Factor);
    Bluetooth_Send_Data('\n');
}
void sendCodeAndDistance(void){
    dutyTrans(distance);
    Bluetooth_Send_Data(',');
    dutyTrans(CodePerid);
    Bluetooth_Send_Data('\n');
}

float filter(float value)
{
    float new_value;
    new_value = get_echo_length();
    if((value-new_value<A)||(new_value-value<A))
        return new_value;
    else return value;
}

//PID初始化参数（暂定）
void PID_init(){
    pid.SetSpeed=0.0;
    pid.ActualSpeed=0.0;
    pid.err=0.0;
    pid.err_last=0.0;
    pid.voltage=0.0;
    pid.integral=0.0;
    pid.Kp=0.2;
    pid.Ki=0.015;
    pid.Kd=0.2;
}
//PID函数
float PID_realize(float speed){
    pid.SetSpeed=speed;
    pid.err=pid.SetSpeed-pid.ActualSpeed;
    pid.integral+=pid.err;
    pid.voltage=pid.Kp*pid.err+pid.Ki*pid.integral+pid.Kd*(pid.err-pid.err_last);
    pid.err_last=pid.err;
    pid.ActualSpeed=pid.voltage*1.0;
    return pid.ActualSpeed;
}

/*****************************主函数***********************************/
//CPU0主函数，置于循环中用户主要逻辑计算区
void UserCpu0Main(void) //样例：蓝牙遥控小车
{
  uint8 a=0;
  myduty=0;
  myangle=0;
  motor_duty(myduty);
  steer_angle(myangle);

  while(TRUE)
  {
      a=Bluetooth_Read_Data();
      if (a!=0)
          ctldata=a;
      switch (ctldata)
      {
      case 'W':      //前进
          myduty--;
          ctldata='w';
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myduty);
          break;
      case 'S':      //后退
          myduty++;
          ctldata='s';
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myduty);
          break;
      case 'A':       //右转
          myangle+=5;
          ctldata='a';
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myangle);
          break;
      case 'D':      //左转
          myangle-=5;
          ctldata='d';
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myangle);
          break;
      case 'E':       //刹车
          myangle=0;
          myduty=0;
          ctldata='e';
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myduty);
          break;
      case 'Z':
          ctldata='z';
          Bluetooth_Send_Data(ctldata);
          break;
      case 'X':
          ctldata='x';
          Bluetooth_Send_Data(ctldata);
          break;
      case 'C':
          ctldata='c';
          Bluetooth_Send_Data(ctldata);
          break;
      case 'Q':
          myduty=-20;    //超级快速前进
          ctldata='q';
          motor_duty(myduty);
          dutyTrans(myduty);
          break;
      case 'O':       //快速转向
          myangle=50;
          ctldata='o';
          steer_angle(myangle);
          dutyTrans(myangle);
          break;
      case 'P':     //快速转向
          myangle=-50;
          ctldata='p';
          steer_angle(myangle);
          dutyTrans(myangle);
          break;
      case 'I':      //超声波停车（暂时使用）
          ctldata='i';
          myangle=0;
          myduty=-10;
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myduty);
          while(1)
          {
              if(distance<200)
              {
                  ctldata='E';
                  break;
              }
          }
          break;
      case 'M':      //自律定速巡航
          ctldata='i';
          PID_init();
          float speed=1.0*CodePerid*CodePeridIndex;//——————————————
          int count=0;
          while(count<100)
          {
              speed=PID_realize(15.0);
              myduty=speed;
              motor_duty(myduty);
              dutyTrans(myduty);
              delay_ms(100);
              count++;
          }
          break;
      default:
          break;
      }
      //TODO::处理传感器事件，如：磁感应停车、超声波停车等等

      if(distance<120)   //不要输入I的自动超声波停车
        {
            myduty=0;
            motor_duty(myduty);
            dutyTrans(myduty);
            delay_ms(100);
        }
    }
}

//CPU1主函数，置于循环中，摄像头读写由此核处理，建议用于摄像头相关计算：
//不要写成死循环，后面有AD相关处理
void UserCpu1Main(void) {
    //每采集好一张图片LED2闪烁一次，可选通过串口发送图像

    if (CAMERA_GetFlag() == 2) // 当值为2时，图像数据加载完毕，方可进行图像读取及处理操作
    {
      PIN_Write(P33_9, 0);
      delay_ms(10);
      PIN_Write(P33_9, 1);
      delay_ms(100);
      //向串口发送图像，运行时间较长，只有在使用上位机观察图像时启用,注意！在用上位机观察图像时一定要关闭所有其他占用串口的进程，否则会造成干扰！
      //CAMERA_Reprot();
      CAMERA_ResetFlag();

      //TODO:进行图像处理，得到新一轮的马达与舵机控制参数
      //遍历储存摄像头获取的图片信息的数组,二值化示例
      for(int i = 0;i < IMAGEH;i++){
          for(int j = 0;j < IMAGEW;j++){
              if(Camera_Output[i][j] > threshold){
                  binary[i][j] = 255;
              }
              else{
                  binary[i][j] = 0;
              }
          }
      }
      int counterLeftWhite=0;
      int counterRightWhite=0;
      int counterLeftRightDifference;
      for(int i = 0;i < IMAGEH;i++){
           for(int j = 0;j < IMAGEW;j++){
                if((binary[i][j] == 0)&&(j<IMAGEW/2)){
                    counterLeftWhite++;
                  }
                if((binary[i][j] == 0)&&(j>=IMAGEW/2)){
                    counterRightWhite++;
                }
              }
          }
      counterLeftRightDifference=counterLeftWhite-counterRightWhite;//左右白度的差
      
      if((counterLeftRightDifference>=500)&&(counterLeftRightDifference<=thresholdFordegreeOfSteering))  //实现转向角度的分层调控（调整阈值待定）
      {
          myangle+=2;
          if(myangle<=30)
              myangle=30;
          steer_angle(myangle);
          dutyTrans(myangle);
          delay_ms(10);
          }
      if((counterLeftRightDifference<=500)&&(counterLeftRightDifference>=-500))
      {
          myangle=0;
          myduty++;
          if(myduty>=15)
              myduty=15;
          motor_duty(myduty);
          steer_angle(myangle);
          dutyTrans(myduty);
      }
      if((counterLeftRightDifference<-500)&&(counterLeftRightDifference>=-thresholdFordegreeOfSteering))  //实现转向角度的分层调控（调整阈值待定）
      {
          myangle-=2;
          if(myangle>=-30)
              myangle=-30;
          steer_angle(myangle);
          dutyTrans(myangle);
          delay_ms(10);
          }
      if(counterLeftRightDifference>thresholdFordegreeOfSteering)
      {
          myangle+=5;
          if(myangle<=30)
                myangle=30;
          steer_angle(myangle);
          dutyTrans(myangle);
          delay_ms(10);
          }
      if(counterLeftRightDifference<-thresholdFordegreeOfSteering)
      {
          myangle-=5;
          if(myangle>=-30)
                myangle=-30;
          steer_angle(myangle);
          dutyTrans(myangle);
          delay_ms(10);
          }
      //BINARY_Report();
    }

}

/**************************************中断调用函数****************************************/
//该函数每10ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt10ms(void) {
    return 0;
}
//该函数每100ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
//样例，获取编码器输出频率与超声举例
uint32 UserInterupt100ms(void) {
    if(sign==0)
    {
        distance = get_echo_length();           //获取超声波距离
        sign++;
        value=distance;
    }else
    {
        distance = filter(value);
        value = distance;
    }
//    printf("distance %f",distance);       //可在FSS界面输出log，替代在watch界面查看distance
//    dutyTrans(distance);                  //借助dutyTrans通过串口发送distance

      CodePerid = GetCodePerid();             //获取编码器输出频率

//    printf("CodePerid %f\n",CodePerid);   //可在FSS界面输出log，替代在watch界面查看CodePerid
//    dutyTrans(CodePerid);                 //借助dutyTrans通过串口发送CodePerid

    //MPU6050
    sendMPU6050Data();                    //通过串口发送MPU6050陀螺仪数据
    sendCodeAndDistance();             //通过串口发送MPU6050陀螺仪数据
    MPU6050debug();
    return 0;
}
//该函数每1000ms执行一次，请在该函数中书写程序，中断时间有限，不要太长
uint32 UserInterupt1000ms(void) {
    return 0;
}

void UserInteruptIO(void) {
}


