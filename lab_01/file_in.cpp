


/*Prastav Atreya Sewani*/
//lab01_C++
//Read the input, calculate the averge per brand and per category and ouput to a file.


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

int main() {

  // define variables
  string sku, brand, category, year, price;
  vector<int>vSKU;
  vector<string>vBrand;
  vector<string>vCategory;
  vector<int>vYear;
  vector<float>vPrice;

  ifstream in_stream;
  in_stream.open("data.csv"); //opening the file.

  if (in_stream.is_open()) { //if the file is open

    string line;

    while (!in_stream.eof()) { //while the end of file is NOT reached
// Fields: sku,brand,category,year,price
     getline(in_stream, sku, ',');
     stringstream ssku(sku);
     int iSKU = 0;
     ssku >> iSKU;
     vSKU.push_back(iSKU);

     getline(in_stream, brand, ',');
     vBrand.push_back(brand);

     getline(in_stream, category, ',');
     vCategory.push_back(category);

     getline(in_stream, year, ',');
     stringstream syear(year);
     int iYear;
     syear >> iYear;
     vYear.push_back(iYear);

     getline(in_stream, price, '\n');
     stringstream sprice(price);
     float fPrice;
     sprice >> fPrice;
     vPrice.push_back(fPrice);
     
    }

    in_stream.close(); //close the file

    // write to output file
    ofstream out_stream;
    out_stream.open("output.txt");

    //calculate the average price for each brand
    out_stream << "Brand    Average" << endl;
    for (int i = 1; i < vBrand.size(); i++) {
      float fAverage = 0;
      int iCount = 0;
      for (int j = 1; j < vBrand.size(); j++) {
        if (vBrand[i] == vBrand[j]) {
          fAverage += vPrice[j];
          iCount++;
        }
      }
      fAverage = fAverage / iCount;
      sort(vBrand.begin(), vBrand.begin()+vBrand.size());
      if (vBrand[i] != vBrand[i+1]){
        out_stream<< vBrand[i] << "     " << fAverage << endl<< endl;
        cout<< vBrand[i]<<"    " << fAverage << endl;
      }
    }
    cout<< endl;

//calculate the average price for each category
    out_stream << "Category    Average" << endl;
    for (int i = 1; i < vCategory.size(); i++) {
      float fAverage = 0;
      int iCount = 0;
      for (int j = 1; j < vCategory.size(); j++) {
        if (vCategory[i] == vCategory[j]) {
          fAverage += vPrice[j];
          iCount++;
        }
      }
      fAverage = fAverage / iCount;
      sort(vCategory.begin(), vCategory.begin()+vCategory.size());
      if (vCategory[i] != vCategory[i+1]){
      out_stream << vCategory[i] << "   " << fAverage << endl<< endl;
      cout<< vCategory[i]<<" " << fAverage << endl;
      }
    }
    
    cout<< endl;
    // list unique years
    vector<int>vYearUnique;
    for (int i = 0; i < vYear.size(); i++) {
      bool found = false;
      for (int j = 0; j < vYearUnique.size(); j++) {
        if (vYear[i] == vYearUnique[j]) {
          found = true;
        }
      }
      if (!found) {
        vYearUnique.push_back(vYear[i]);
      }
    }

    // print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
    for (int i = 1; i < vYearUnique.size(); i++) {
      cout << vYearUnique[i] << " (";
      out_stream << vYearUnique[i] << " (";
      int count = 0;
      for (int j = 1; j < vYear.size(); j++) {
        if (vYear[j] == vYearUnique[i]) {
          count++;
        }
      }
      cout << count << "): ";
      out_stream << count << "): ";
      for (int j = 1; j < vYear.size(); j++) {
        if (vYear[j] == vYearUnique[i]) {
          cout << vSKU[j] << ", ";
          out_stream << vSKU[j] << ", ";
        }
      }
      cout << endl;
      out_stream << endl;
      
    }
    out_stream.close();

  } else {
    cout << "Error opening file." << endl;
  }
  
  return 0;
}
