#include <iostream>
#include <vector>

using namespace std;

int abs(int num){return(num<0 ? -num:num);}

void print_vector ( vector <int> *arr ) {
  vector <int> larr = *arr;cout << "[ ";
  for(  int i = 0; i < larr.size() ; i++ ) {
  cout<<larr[i]<<", ";}cout<<"]"<<endl;return;
}

int find_coords( vector <int> *array ) {
  int max_weight = 0;
  int pair_intial_index;
  vector <int> local_array = *array;
  int size = local_array.size();
  static int total_weight = 0;

  print_vector( array );
  // Pushing the first elment at the to make it circular ish.
  local_array.push_back(local_array.front());
  
  for ( int i = 0 ; i < size ; i++ ) { // Iterate over size maybe
    int difference = abs(local_array[i] - local_array[i+1]);
    if ( difference > max_weight ) {
      max_weight = difference;
      pair_intial_index = i;
    }
  }
  total_weight += max_weight;
  cout << "Selected node weights: "<<local_array[pair_intial_index]<<", "
       <<local_array[pair_intial_index+1]<<endl<<endl;
  
  if (size==2) {
    cout <<"Finished Solving."<<endl;
    return(total_weight);
  }

  local_array.pop_back(); //Removes the extra added element at the last
  auto begin = local_array.begin();
  local_array.erase( begin + pair_intial_index);
  local_array.erase( begin + pair_intial_index % size);
  
  find_coords( &local_array );return(total_weight);
}

int main ( void ) {
  vector <int> input;
  /*input.push_back(6);
  input.push_back(2);
  input.push_back(8);
  input.push_back(5);
  input.push_back(6);
  input.push_back(9);
  input.push_back(5);
  input.push_back(3);*/
  int n;cout << "Enter the value of n: ";
  cin >> n;for ( int i = 0; i < (2*n) ; i++ ) {
  int temp;cout << "Enter Node" << i << ":";cin >> temp;
  input.push_back(temp);}
  int t_w = find_coords( &input );
  cout << "Total weight is: " << t_w << endl;return(0);
}
