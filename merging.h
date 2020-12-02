using namespace std;

template <typename T>
class Merger {
    virutal T& merge(T& first, T& second);
};

class NetworkMerger : Merger<int> {
    int merge(int first, int other) {
        return 0;
    }
};