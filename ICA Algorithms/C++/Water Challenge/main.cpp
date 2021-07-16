#include "main.h"

using namespace std;

void generate_summary(Container *ca, Container *cb, Container *cc) {
  cout << "Container 1 has " << ca->get_alloc_string() << " and can contain " << ca->get_capacity_string() << endl;

  cout << "Container 2 has " << cb->get_alloc_string() << " and can contain " << cb->get_capacity_string() << endl;

  cout << "Container 3 has " << cc->get_alloc_string() << " and can contain " << cc->get_capacity_string() << endl;
}

int main() {
  Container* container_sm = new Container(3, 0);
  Container* container_md = new Container(5, 0);
  Container* container_lg = new Container(8, 8);

  while (container_lg->get_alloc() != 4) {
    int move_from;
    int move_to;

    generate_summary(container_sm, container_md, container_lg);

    cout << endl << "Pour the contents of container (1,2,3) ";
    cin >> move_from;

    cout << "                  to container (1,2,3) ";
    cin >> move_to;
    cout << endl;

    if (move_from >= 1 && move_from <= 3 &&
        move_to   >= 1 && move_to   <= 3) {
      // lol
      if (move_from == 1 && move_to == 2) {
        int remainder = container_md->set_alloc( container_sm->get_alloc() );
        container_sm->set_alloc( -(container_sm->get_alloc()-remainder) );
      } else if (move_from == 3 && move_to == 2) {
        int remainder = container_md->set_alloc( container_lg->get_alloc() );
        container_lg->set_alloc( -(container_lg->get_alloc()-remainder) );
      } else if (move_from == 1 && move_to == 3) {
        int remainder = container_lg->set_alloc( container_sm->get_alloc() );
        container_sm->set_alloc( -(container_sm->get_alloc()-remainder) );
      } else if (move_from == 2 && move_to == 3) {
        int remainder = container_lg->set_alloc( container_md->get_alloc() );
        container_md->set_alloc( -(container_md->get_alloc()-remainder) );
      } else if (move_from == 2 && move_to == 1) {
        int remainder = container_sm->set_alloc( container_md->get_alloc() );
        container_md->set_alloc( -(container_md->get_alloc()-remainder) );
      } else if (move_from == 3 && move_to == 1) {
        int remainder = container_sm->set_alloc( container_lg->get_alloc() );
        container_lg->set_alloc( -(container_lg->get_alloc()-remainder) );
      } else {
        cout << "Can't do the same container." << endl << endl;
      }
    } else {
      cout << "Invalid container requested (both must be 1, 2, 3)." << endl << endl;
    }
  }

  cout << "Congratulations! You got it." << endl;

  return 0;
}