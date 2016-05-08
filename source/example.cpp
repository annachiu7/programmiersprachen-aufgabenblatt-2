#include "window.hpp"
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(600,600)};

  while (!win.should_close()) {
    if (win.is_key_pressed(GLFW_KEY_ESCAPE)) {
      win.close();
    }

    auto t = win.get_time();
    float x1{0.5f + 0.4f * std::sin(t*M_PI/30)};
    float y1{0.5f + 0.4f * std::cos(t*M_PI/30)};

    float x2{0.5f + 0.3f * std::sin(t*M_PI/30/60)};
    float y2{0.5f + 0.3f * std::cos(t*M_PI/30/60)};

    float x3{0.5f + 0.2f * std::sin(t*M_PI/30/60/60)};
    float y3{0.5f + 0.2f * std::cos(t*M_PI/30/60/60)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    win.draw_line(0.5f, 0.5f, x1, y1, 1, 0, 0);
    win.draw_line(0.5f, 0.5f, x2, y2, 0, 1, 0);
    win.draw_line(0.5f, 0.5f, x3, y3, 0, 0, 1);

    auto m = win.mouse_position();
    //win.draw_line(0.1f, 0.1f, 0.8f,0.1f, 1.0,0.0,0.0);

    win.draw_line(0.0f, m.second, 0.01f, m.second, 0.0, 0.0, 0.0);
    win.draw_line(0.99f, m.second,1.0f, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0.0f, m.first, 0.01f, 0.0, 0.0, 0.0);
    win.draw_line(m.first, 0.99f,m.first, 1.0f, 0.0, 0.0, 0.0);

    // create mouse position vector
    Vec2 mp;
    mp.x = m.first;
    mp.y = m.second;
    // create rec
//    Rectangle rec{0.1,0.1,0.3f,0.2f,{0.0,0.0,0.0}};
//    rec.draw(win, rec.get_Color());
//    if (rec.is_inside(mp)  ==  true)
//    {
//      rec.draw(win, {0.0,0.0,1.0});
//    }
//    else{
//      rec.draw(win, rec.get_Color());
//    }
    //create circle
    Circle c{0.5,0.5,0.43,{0.0}};
    c.draw(win, {0.0});
    if (c.is_inside(mp) == true)
    {
      c.draw(win, {0.0,0.0,1.0});
    }
    else{
      c.draw(win, c.get_Color());
    }

    win.update();
  }

  return 0;
}
