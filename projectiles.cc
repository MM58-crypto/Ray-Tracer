#include<iostream>
#include<math.h>
#include<tuple>
#include"ray-tracer-tests.cc"
using namespace std;

//use create point and vectors funcs written yesterday
class Projectile {
    public:
        tuple <int, int, int, int> position;
        tuple <int, int, int, int> velocity;

        Projectile(const tuple<int, int, int, int>& pos, const tuple<int, int, int, int>& vel) {
            position = pos;
            velocity = vel;
        }
};

class Environment {
    public:
        tuple <int, int, int, int> gravity;
        tuple <int, int, int, int> wind;
        Environment(const tuple<int, int, int, int>& grav, const tuple<int, int, int, int>& w) {
            gravity = grav;
            wind = w;
        }


};

Projectile tick(const Environment& env_obj, const Projectile& proj_obj) {
   tuple <int, int, int> new_position = addTuples(proj_obj.position, proj_obj.velocity);
   tuple <int, int, int> new_velocity = addTuples(proj_obj.position, env_obj.gravity);
   return Projectile(new_position, new_velocity);
}


int main() {








return 0;
}
