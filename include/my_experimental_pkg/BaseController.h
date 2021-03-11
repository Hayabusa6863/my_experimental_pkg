// コントローラの雛形
// すべてのコントローラに共通する処理（初期化，宣言など）をここにまとめたい
// 実際に回す部分（cmdの格納）は別のファイルでoverrideする
#ifndef BASE_CONTROLLER_H_
#define BASE_CONTROLLER_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>

// 基底クラスのコンストラクタは基本的にデフォルトコンストラクタが呼ばれる
// 引数付きで呼ぶにはどうしたらよいか？

class BaseController{
private:
    const double controller_frequency = 100.0;   // コントローラ周波数[Hz]
    ros::NodeHandle nh;
    std::string topic_name = "value";
    ros::Time t_start;
    double rosparam_value;  // rosparamから読み取って格納する変数

protected:  // 継承したファイルでも使用したい変数
    std_msgs::Float64 msg;
    ros::Publisher pub;
    ros::Timer timer;
    
public:
    BaseController(void);
    void timer_start(void);
    double getTime(void);

    virtual void loop(const ros::TimerEvent&) = 0;    // ROSのpublishなどループで回す部分
    virtual ~BaseController(){};
};

#endif