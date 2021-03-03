// cos波の値を出力するコントローラ
// Controllerクラス（抽象クラス）の処理をoverrideして上書き
#include <my_experimental_pkg/BaseController.h>

class cosinewave_controller : public BaseController{
private:
    const double wave_frequency = 1.0;

public:
    cosinewave_controller(ros::NodeHandle *nh_)
        : BaseController(nh_){}

    virtual void loop(const ros::TimerEvent& e) override{
        msg.data = cos(2*M_PI*wave_frequency*getTime());
        pub.publish(msg);
    }
};


int main(int argc, char** argv){
    ros::init(argc, argv, "cosinewave_controller");
    ros::NodeHandle nh;
    
    BaseController *controller;
    controller = new cosinewave_controller(&nh);
    
    ros::spin();
    return 0;
}