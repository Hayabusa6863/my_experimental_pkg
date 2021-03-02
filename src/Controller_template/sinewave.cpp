// sin波の値を出力するコントローラ
// Controllerクラス（抽象クラス）の処理をoverrideしてできるようにしたい．
#include <my_experimental_pkg/ControllerInterface.h>

class sinewave_controller : public ControllerInterface{
private:
    const double wave_frequency = 1.0;

public:
    sinewave_controller(ros::NodeHandle *nh_)
        : ControllerInterface(nh_){}

    virtual void loop() override{
        while(ros::ok()){
            msg.data = sin(2*M_PI*wave_frequency*getTime());
            pub.publish(msg);
            loop_rate->sleep();
            ros::spinOnce();
        }
    }
};

int main(int argc, char** argv){
    ros::init(argc, argv, "sinewave_controller");
    ros::NodeHandle nh;
    ControllerInterface *controller;

    controller = new sinewave_controller(&nh);

    controller->loop();
}