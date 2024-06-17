#include<iostream>
#include<math.h>
#include"ray-tracer-tests.cc"

using namespace std;

class Color {
    public:
        double red, green , blue;

        Color(double r= 0, double g = 0 , double b = 0) {
            red = r;
            green = g;
            blue = b;
        }
        // Equality operator to easily compare colors (c++ == operator can't natively compare user-defined types like objects from classes)
        bool operator==(const Color& other) const {
            return red == other.red && green == other.green && blue == other.blue;
        }


    // Friend function to overload the << operator for the Color class
        friend std::ostream& operator<<(std::ostream& os, const Color& color) {
            os << "Color(" << color.red << ", " << color.green << ", " << color.blue << ")";
            return os;
        }
};

class Canvas {
    public:
        double width;
        double height;
        // how to represent pixel?
        std::vector<std::vector<Color>> pixels;
        Canvas(double w, double h) {
            width = w;
            height = h;
            pixels = std::vector<std::vector<Color>>(height, std::vector<Color>(width, Color(0, 0, 0)));
        }
        void write_pixel(double x, double y, Color color_obj) {
    // sets the color of a pixel at a particular position in canvas
    // if statements?
           if (x>=0 && x < width && y >=0 && y < height) {
               pixels[y][x] = color_obj;
           }
        }

        Color pixel_at(double x , double y) {
            if (x>=0 && x < width && y >=0 && y < height) {
               return pixels[y][x];
           }
            return Color();
        }
        void canvas_to_ppm(/* Canvas canv(double x, double y) */) {
            std::cout << "P3 \n";
            std::cout << width << " "<< height <<  endl;
            std::cout << "255 \n";
            //return "P3 \n 255 \n";
            // for loop? (pixel data)
            for (int h=0; h < height; h++) {
                for (int w=0; w < width; w++) {
                    Color pixel = pixel_at(w, h);
                    int max = 255;
                    int min = 0;
                    // clamp is used as max color val is 255 & min color val is 0
                    int r = std::clamp(static_cast<int>(pixel.red * max), min, max);
                    int g = std::clamp(static_cast<int>(pixel.green * max), min, max);
                    int b = std::clamp(static_cast<int>(pixel.blue * max), min, max);

                    std::cout << r << " " << g << " " << b;
                    // space between values in the canvas
                    if (w < width - 1) {

                        cout << " ";
                    }
                }
                cout << "\n";
            }

        }
};
