// コントローラの雛形（≒インターフェースクラス）
// すべてのコントローラに共通する処理（初期化，宣言など）をここにまとめたい
// 実際に回す部分（cmdの格納）は別のファイルでoverrideする

#include <my_experimental_pkg/BaseController.h>

BaseController::BaseController(ros::NodeHandle* nh_){
    nh = nh_;

    // タイマ割り込みの設定
    timer = nh->createTimer(ros::Duration(1.0/controller_frequency), &BaseController::loop, this);
    pub = nh->advertise<std_msgs::Float64>(topic_name, 1);
    usleep(50000);  // delayを入れないと指令値の最初のほうが欠落する！
    timer_start();
}

// タイマのリセット
void BaseController::timer_start(void){
    t_start = ros::Time::now();
}

// プログラムが実行されてからの時間を返す
// 時間をリセットしたい場合はtimer_start()を実行
double BaseController::getTime(void){
    return (ros::Time::now() - t_start).toSec();
}