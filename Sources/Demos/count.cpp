//creer une classe kant qui irite lapplication  surcharge les methodes drow setup et updates

#include "count.h"

namespace nkentseu {
    Count::Count(const ApplicationProperties& props)  
        : Application(props) {} 
        
    void Count::Setup() {
        position.x = 100.0f;
        position.y = GetWindowHeight() / 2.0f;
    }

    void Count::Update(float deltaTime) {
        position.y += gravity * deltaTime * 50;
        if (position.y>= GetWindowHeight() + r){
            position.y -= friction * deltaTime * 50;
        }
        
    }

    void Count::Draw() {
       Background(graphics::Color::White, true);
       Fill(graphics::Color::Green);
       Circle(position, r); 
    }

}