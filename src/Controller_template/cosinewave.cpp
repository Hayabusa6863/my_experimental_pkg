// cos波の値を出力するコントローラ
// Controllerクラス（抽象クラス）の処理をoverrideしてできるようにしたい．
#include <my_experimental_pkg/ControllerInterface.h>

class cosinewave_controller : public ControllerInterface{
private:
    const double wave_frequency = 1.0;

public:
    cosinewave_controller(ros::NodeHandle *nh_)
        : ControllerInterface(nh_){}


    virtual void loop() override{
        while(ros::ok()){
            msg.data = cos(2*M_PI*wave_frequency*getTime());
            pub.publish(msg);
            loop_rate->sleep();
            ros::spinOnce();
        }
    }
};

int main(int argc, char** argv){
    ros::init(argc, argv, "cosinewave_controller");
    ros::NodeHandle nh;
    ControllerInterface *controller;

    controller = new cosinewave_controller(&nh);

    controller->loop();
}