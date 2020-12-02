#pragma once

class Tuple {
    public:
        int index;
        double intensity;
        
        Tuple() : index(0), intensity(0) { }
        Tuple(int x, double y) : index(x), intensity(y) { }

        int getIndex() {
            return index;
        }

        int getIntensity() {
            return intensity;
        }
};