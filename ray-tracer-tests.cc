#include<gtest/gtest.h>
#include<iostream>
#include<math.h>
#include<tuple>
#include<vector>

using namespace std;

// create points
tuple<int, int, int, int> createPoint(const tuple<int, int, int>& x1) {
   int x1_1, x1_2, x1_3;
   tie( x1_1, x1_2, x1_3)= x1;
   return make_tuple(x1_1, x1_2, x1_3, 1);

}
// create vectors
tuple<int, int, int, int> createVector(const tuple<int, int, int>& x1) {
   int x1_1, x1_2, x1_3;
   tie( x1_1, x1_2, x1_3)= x1;
   return make_tuple(x1_1, x1_2, x1_3, 0);

}
// adding tuples

tuple<int, int, int, int> addTuples(const tuple<int, int, int, int>& a1, const tuple<int, int, int, int>& a2) {
    int a1_1, a1_2, a1_3, a1_4;
    int a2_1, a2_2, a2_3, a2_4;
    tie(a1_1, a1_2, a1_3, a1_4) = a1;
    tie(a2_1, a2_2, a2_3, a2_4) = a2;
    return make_tuple(a1_1 + a2_1, a1_2 + a2_2, a1_3 + a2_3, a1_4 + a2_4);
}
//function to subtract tuples
tuple<int, int, int> subtractTuples(const tuple<int, int, int>& a1, const tuple<int, int, int>& a2) {
    int a1_1, a1_2, a1_3;
    int a2_1, a2_2, a2_3;
    tie(a1_1, a1_2, a1_3) = a1;
    tie(a2_1, a2_2, a2_3) = a2;
    return make_tuple(a1_1 - a2_1, a1_2 - a2_2, a1_3 - a2_3);
}

// scalar multiplication (eg. 3.5)
tuple<double, double, double, double> scalarMultiply(const tuple<int, int, int, int>& a1) {
    int a1_1, a1_2, a1_3, a1_4;
    //int a2_1, a2_2, a2_3;
    tie(a1_1, a1_2, a1_3, a1_4) = a1;
    //tie(a2_1, a2_2, a2_3) = a2;
    return make_tuple(a1_1 * 3.5, a1_2 * 3.5, a1_3 * 3.5, a1_4 * 3.5);

}
// computing magnitude of a vector
 double getMagnitude(const tuple<int, int, int>& a1) {
    int a1_1, a1_2, a1_3;
    //int a2_1, a2_2, a2_3;
    tie(a1_1, a1_2, a1_3) = a1;
    //tie(a2_1, a2_2, a2_3) = a2;
    return sqrt(pow(a1_1,2) + pow(a1_2,2) + pow(a1_3,2));

}
// Normalize Vectors
tuple<int, int, int> normalizeVector(const tuple<int, int, int>& v1) {
    int v1_1, v1_2, v1_3;
    tie(v1_1, v1_2, v1_3) = v1;
    return make_tuple(v1_1/getMagnitude(v1), v1_2/getMagnitude(v1), v1_3/getMagnitude(v1) );

}
// Dot product
float  dotProduct(const tuple <float, float, float>& v1, const tuple<float, float, float>& v2) {
    float v1_1, v1_2, v1_3;
    float v2_1, v2_2, v2_3;
    tie(v1_1, v1_2, v1_3) = v1;
    tie(v2_1, v2_2, v2_3) = v2;

    return (v1_1 * v2_1) + (v1_2 * v2_2) + (v1_3 * v2_3);

}
// Cross product
tuple<int, int, int> crossproduct(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    int a_1, a_2, a_3;
    int b_1, b_2, b_3;
    tie(a_1, a_2, a_3) = a;
    tie(b_1, b_2, b_3) = b;

    return make_tuple(a_2 * b_3 - a_3 * b_2, a_3 * b_1 - a_1 * b_3, a_1 * b_2 - a_2 * b_1);

}
// Color tuple <-- wrong needs to be fixed
double colorTuple(const tuple<double, double ,double>& a1) {
    double a1_1, a1_2, a1_3;
    tie(a1_1, a1_2, a1_3) = a1;

    return get<0>(a1);
}
//modify it later
tuple <double, double, double> AddColors(const tuple<double, double, double>& c1, const tuple<double, double, double>& c2) {
    double c1_1, c1_2, c1_3;
    double c2_1, c2_2, c2_3;
    tie(c1_1, c1_2, c1_3) = c1;
    tie(c2_1, c2_2, c2_3) = c2;

    return make_tuple(c1_1 + c2_1, c1_2 + c2_2, c1_3 + c2_3);

}
tuple <float, float, float> subtractColors(const tuple<float, float, float>& c1, const tuple<float, float, float>& c2) {
    float c1_1, c1_2, c1_3;
    float c2_1, c2_2, c2_3;
    tie(c1_1, c1_2, c1_3) = c1;
    tie(c2_1, c2_2, c2_3) = c2;

    return make_tuple(c1_1 - c2_1, c1_2 - c2_2, c1_3 - c2_3);

}
tuple <double, double, double> ColorScalarMulti(const tuple<double, double, double>& c1) {
    double c1_1, c1_2, c1_3;
    tie(c1_1, c1_2, c1_3) = c1;

    return make_tuple(c1_1 * 2, c1_2 * 2, c1_3 * 2);

}
tuple <double, double, double> hadamard_product(const tuple<double, double, double>& c1 , const tuple<double, double, double>& c2) {
    double c1_r, c1_g, c1_b;
    double c2_r, c2_g, c2_b;
    tie(c1_r, c1_g, c1_b) = c1;
    tie(c2_r, c2_g, c2_b) = c2;

    return make_tuple(c1_r * c2_r, c1_g * c2_g, c1_b * c2_b);
}

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

// pixel
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
        }
};



TEST(TuplesFeatures, CreatePoint) {
    tuple<int, int, int> a1 = make_tuple(3, -2, 5);
    tuple<int, int, int, int> expectedResult = make_tuple(3, -2, 5, 1);

    tuple<int, int, int, int> result = createPoint(a1);

    ASSERT_EQ(result, expectedResult);
}
TEST(TuplesFeatures, CreateVector) {
    tuple<int, int, int> a1 = make_tuple(3, -2, 5);
    tuple<int, int, int, int> expectedResult = make_tuple(3, -2, 5, 0);

    tuple<int, int, int, int> result = createVector(a1);

    ASSERT_EQ(result, expectedResult);
}
TEST(TuplesFeatures, AddingTwoTuples) {
    tuple<int, int, int, int> a1 = make_tuple(3, -2, 5, 1);
    tuple<int, int, int, int> a2 = make_tuple(-2, 3, 1, 0);
    tuple<int, int, int, int> expectedResult = make_tuple(1, 1, 6, 1);

    tuple<int, int, int, int> result = addTuples(a1, a2);

    ASSERT_EQ(result, expectedResult);
}

TEST(TuplesFeatures, SubtractTwoTuples) {
     tuple<int, int, int> p1 = make_tuple(3, 2, 1);
     tuple<int, int, int> p2 = make_tuple(5, 6, 7);
     tuple<int, int, int> expected_result = make_tuple(-2, -4, -6);

     tuple<int, int, int> actual_result = subtractTuples(p1, p2);
     ASSERT_EQ(actual_result, expected_result);

}

TEST(TuplesFeatures, MultiplyaTuple) {
     tuple<int, int, int, int> a = make_tuple(1, -2, 3, -4);
     tuple<double, double, double, double> expected_result = make_tuple(3.5, -7, 10.5, -14);

     tuple<double, double, double, double> actual_result = scalarMultiply(a);
     ASSERT_EQ(actual_result, expected_result);

}

TEST(TuplesFeatures, GetMagnitude) {
    tuple<int, int, int> v = make_tuple(1, 2, 3);
    double expected_result = sqrt(14);
    double actual_result = getMagnitude(v);

    ASSERT_EQ(actual_result, expected_result);

}

TEST(TuplesFeatures, NormalizeVector) {
    tuple<int, int, int> vec = make_tuple(4, 0 ,0);
    tuple<int, int, int> expected_result = make_tuple(1, 0, 0);

    tuple<int, int, int> actual_result = normalizeVector(vec);

    ASSERT_EQ(actual_result, expected_result);


}

TEST(TuplesFeatures, Dotproduct) {
    tuple<float, float, float> vec1 = make_tuple(1, 2, 3);
    tuple<float, float, float> vec2 = make_tuple(2, 3, 4);
    float expected_result = 20;

    float actual_result = dotProduct(vec1, vec2);

    ASSERT_EQ(actual_result, expected_result);
}

TEST(TuplesFeatures, Crossproduct) {
     tuple<int, int, int> a = make_tuple(1, 2, 3);
     tuple<int, int, int> b = make_tuple(2, 3, 4);
     tuple<int, int, int> expected_result = make_tuple(-1, 2, -1);

     tuple<int, int, int> actual_result = crossproduct(a,b);

     ASSERT_EQ(actual_result, expected_result);

}
TEST(TuplesFeatures, CreateColor) {
    Color color(-0.5, 0.4, 1.7);

    ASSERT_EQ(color.red, -0.5);
    ASSERT_EQ(color.green, 0.4);
    ASSERT_EQ(color.blue, 1.7);

}


TEST(TuplesFeatures, AddColors) {
    tuple<double, double, double> c1 = make_tuple(0.9, 0.6, 0.75);
    tuple<double, double, double> c2 = make_tuple(0.7, 0.1, 0.25);
    tuple<double, double, double> expectedResult = make_tuple(1.6, 0.7, 1.0);

    tuple<double, double, double> result = AddColors(c1, c2);

    ASSERT_EQ(result, expectedResult);
}

TEST(TuplesFeatures, SubtractColors) {
    tuple<float, float, float> c1 = make_tuple(0.9, 0.6, 0.75);
    tuple<float, float, float> c2 = make_tuple(0.7, 0.1, 0.25);
    tuple<float, float, float> expectedResult = make_tuple(0.2, 0.5, 0.5);

    tuple<float, float, float> result = subtractColors(c1, c2);

    const double epsilon = 1e-6;
    ASSERT_NEAR(get<0>(result), get<0>(expectedResult), epsilon);
    ASSERT_NEAR(get<1>(result), get<1>(expectedResult), epsilon);
    ASSERT_NEAR(get<2>(result), get<2>(expectedResult), epsilon);



}

TEST(TuplesFeatures, MultiplyColorByScalar) {
     tuple<double, double, double> c = make_tuple(0.2, 0.3, 0.4);
     tuple<double, double, double> expected_result = make_tuple(0.4, 0.6, 0.8);

     tuple<double, double, double> actual_result = ColorScalarMulti(c);
     ASSERT_EQ(actual_result, expected_result);

}

TEST(TuplesFeatures, Hadamardproduct) {
     tuple<double, double, double> c1 = make_tuple(1, 0.2, 0.4);
     tuple<double, double, double> c2 = make_tuple(0.9, 1, 0.1);
     tuple<double, double, double> expected_result = make_tuple(0.9, 0.2, 0.04);

     tuple<double, double, double> actual_result = hadamard_product(c1,c2);

     const double epsilon = 1e-6;
     ASSERT_NEAR(get<0>(actual_result), get<0>(expected_result), epsilon);
     ASSERT_NEAR(get<1>(actual_result), get<1>(expected_result), epsilon);
     ASSERT_NEAR(get<2>(actual_result), get<2>(expected_result), epsilon);

}
TEST(CanvasFeatures, CreateCanvas) {
     //tuple<double, double> canvas = make_tuple(10,20);
     Canvas canv(10,20);
     ASSERT_EQ(canv.width, 10);
     ASSERT_EQ(canv.height, 20);

     for (size_t y = 0; y < canv.height; ++y) {
         for (size_t x = 0; x < canv.width; ++x) {
             ASSERT_EQ(canv.pixels[y][x].red, 0);
             ASSERT_EQ(canv.pixels[y][x].green, 0);
             ASSERT_EQ(canv.pixels[y][x].blue, 0);
         }
     }
    // double actual_result = createCanvas(canvas);

    // ASSERT_EQ(actual_result, expected_result);

}
TEST(CanvasFeatures, WritePixels) {
     //tuple<double, double> canvas = make_tuple(10,20);
     Canvas canv(10,20);
     Color red(1,0,0); // this is an object
     //std::cout << "Red color: " << red << std::endl; -- Output: Red color: Color(1, 0 ,0)
     canv.write_pixel(2, 3, red);
     //std::cout<< "Pixel at (2, 3) position: " << canv.pixel_at(2,3)<< std::endl;
     ASSERT_EQ(canv.pixel_at(2,3), red);

}
TEST(CanvasFeatures, ppmHeader) {
    Canvas canv(5, 3);
    canv.canvas_to_ppm();
}
TEST(CanvasFeatures, ConstructPPMHeader) {
    Canvas canv(5, 3);
    Color c1(1.5, 0, 0);
    Color c2(0, 0.5, 0);
    Color c3(-0.5, 0, 1);

    canv.write_pixel(0, 0, c1);
    canv.write_pixel(2, 1, c2);
    canv.write_pixel(4, 2, c3);

    canv.canvas_to_ppm();

}
