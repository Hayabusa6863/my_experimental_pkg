// コントローラの雛形（≒インターフェースクラス）
// すべてのコントローラに共通する処理（初期化，宣言など）をここにまとめたい
// 実際に回す部分（cmdの格納）は別のファイルでoverrideする

#include <my_experimental_pkg/ControllerInterface.h>

ControllerInterface::ControllerInterface(ros::NodeHandle* nh_){
    nh = nh_;
    loop_rate = new ros::Rate(controller_frequency);
    pub = nh->advertise<std_msgs::Float64>(topic_name, 1);
}

ControllerInterface::~ControllerInterface(){
    delete loop_rate;
}

void ControllerInterface::timer_start(void){
    t_start = ros::Time::now();
}

double ControllerInterface::getTime(void){
    return (ros::Time::now() - t_start).toSec();
}

