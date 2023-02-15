#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "market.h"

Market market;





int main () {

  market.delete_an_item(18);
  market.print_all_data();
  
  // market.add_an_item("hello");
  // market.print_all_data();
  // market.remove_an_item(1);

}