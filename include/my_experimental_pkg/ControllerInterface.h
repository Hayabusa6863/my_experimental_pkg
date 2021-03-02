// コントローラの雛形
// すべてのコントローラに共通する処理（初期化，宣言など）をここにまとめたい
// 実際に回す部分（cmdの格納）は別のファイルでoverrideする
#ifndef CONTROLLER_INTERFACE_H_
#define CONTROLLER_INTERFACE_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>

// 基底クラスのコンストラクタは基本的にデフォルトコンストラクタが呼ばれる
// 引数付きで呼ぶにはどうしたらよいか？

class ControllerInterface{
private:
    const double controller_frequency = 100.0;   // コントローラ周波数[Hz]
    std::string topic_name = "value";
    ros::Time t_start;
protected:  // 継承したファイルでも使用したい変数
    ros::NodeHandle *nh;
    std_msgs::Float64 msg;
    ros::Rate *loop_rate;    // コンストラクタが必要なので動的に確保した
    ros::Publisher pub;
    
public:
    ControllerInterface(ros::NodeHandle*);
    void timer_start(void);
    double getTime(void);

    virtual void loop() = 0;    // ROSのpublishなど．
    virtual ~ControllerInterface();
};

#endif