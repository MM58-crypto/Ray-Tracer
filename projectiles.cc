#include<iostream>
#include<math.h>
#include<tuple>
#include"ray-tracer-tests.cc"
using namespace std;

class Projectile {
    public:
        tuple <int, int, int> position;
        tuple <int, int, int> velocity;
};

class Environment {
    public:
        tuple <int, int, int> gravity;
        tuple <int, int, int> wind;
};
Projectile proj_obj;
Environment env_obj;
/*
tuple tick(proj_obj, env_obj) {
    position = proj_obj.position + proj_obj.velocity;
    velocity = proj_obj.velocity + env_obj.gravity + env_obj.wind;

}
*/

int main() {








return 0;
}
