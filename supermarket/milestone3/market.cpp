#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "market.h"



struct products {
  std::string name;
  std::string expiry_date;
  std::string type;
  int quantity;
  float price;
};

std::vector<products> item; 



void Market::read_data(){
  std::fstream file("data.txt");
  std::string line;
  


  int id = 0;

  std::string name, expiry_date, type;
  int quantity;
  float price;

  while(getline(file, line)) {
    std::istringstream iss(line);
    if(!(iss >> name >> expiry_date >> quantity >> price >> type))
      throw std::runtime_error("invalid data");
    iss >> name >> expiry_date >> quantity >> price >> type;
    
    item.push_back(products());
    item[id].name = name;
    item[id].expiry_date = expiry_date;
    item[id].quantity = quantity;
    item[id].price = price;
    item[id].type = type;

    id++;
}
file.close();
}


Market m;



void Market::print_all_data(){
    m.read_data();
      for(int i=0; i<item.size(); ++i){
      std::cout << item[i].name << std::endl;
      std::cout << item[i].expiry_date << std::endl;
      std::cout << item[i].quantity << std::endl;
      std::cout << item[i].price << std::endl;
      std::cout << item[i].type << std::endl;
      std::cout << "======================"<<std::endl;
    }
}

void Market::print_one_item(int i){
    m.read_data();
      std::cout << item[i].name << std::endl;
      std::cout << item[i].expiry_date << std::endl;
      std::cout << item[i].quantity << std::endl;
      std::cout << item[i].price << std::endl;
      std::cout << item[i].type << std::endl;

}


// void Market::remove_an_item(int i){
//     m.read_data();
//     std::fstream file("data.txt");
//     std::string line;
//     item.erase(item.begin()+i);
//     std::cout<<"item removed"<<std::endl;
    
// }


void Market::add_an_item(std::string str){
    std::fstream file("data.txt",std::ios::app);
    // std::istringstream iss(str);

    file << "\n"+str;
    file.close();
    }



void Market::delete_an_item(int x){
  std::fstream read_file;

  int line_number;
  line_number = x;


  std::vector<std::string> lines;
  std::string line;

  read_file.open("data.txt");

  while (getline(read_file,line))
      lines.push_back(line);

  read_file.close();

  if (line_number > lines.size()){
    std::cout <<"Line " << line_number;
    std::cout <<" is not in the file." << std::endl;
    std::cout << "File has "<< lines.size();
    std::cout << "lines." << std::endl;

  }

  std::ofstream write_file;
  write_file.open("data.txt");

  if (write_file.fail()){
    std::cout << "Error opening file."<<std::endl;
  }

  line_number--;

  for (int i = 0; i < lines.size(); i++)
    if (i != line_number)
      write_file << lines[i] << std::endl;

    write_file.close();
  
}