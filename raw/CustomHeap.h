#include <queue> 
#include <functional>
using namespace std;

template < typename container >
class CustomHeap {
    private:
    function<bool(container,container)> comparator ;
    priority_queue < container , vector<container> , function<bool(container,container)> > data ;
    public:
    CustomHeap ( function<bool(container,container)> );
    void push ( container );
    void pop ( void );
    container top ( void );
    bool empty ( void );
};

template < typename container > 
CustomHeap<container> :: CustomHeap ( function<bool(container,container)> comparator_input ) {
    priority_queue < container , vector<container> , function<bool(container,container)> > temp_decl ( comparator_input );
    data = temp_decl ;
}

template < typename container >
void CustomHeap<container> :: push ( container input ) {
    data.push ( input );
    return;
}

template < typename container >
void CustomHeap<container> :: pop ( void ) {
    data.pop( ) ;
    return;
}

template < typename container > 
container CustomHeap<container> :: top ( void ) {
    return data.top();
}

template < typename container > 
bool CustomHeap<container> :: empty ( void ) {
     return not (bool) data.size() ;
}