 #include <iostream>
 using namespace std ;

 class Box{
    int width ;
    Box(int _w) : width(_w){};

    public:
    int getwidth() const{
        return width;
    }

    void setwidth(int _val){
        width = _val;
    }
    friend class BoxFactory;
 };

 class BoxFactory{
    int count;
    public:
            Box getabox(int _w){
                ++count;
                // cout << count << endl;
                return Box(_w);
            }

            int getcount(){
                return count;
            }

 };

 int main(){

    BoxFactory bfact;
    Box b = bfact.getabox(5);
    cout << b.getwidth() << endl;
    //cout << bfact.getcount();

    //singleton class concept
    // constructor c++ microsoft article

    

    return 0;
 }