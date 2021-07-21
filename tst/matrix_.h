#define uint unsigned int

template <typename T>
class matrix_ {

 private:
  uint rowDim;
  uint colDim;
  T*        m;

 public:
  matrix_ ( uint rows , uint cols );
  void printStirng (void);
  T* operator [](uint i);

};



template <typename T>
matrix_<T>::matrix_ (uint rows, uint cols ):
  rowDim(rows) , colDim(cols)  {
  // We create a single dim array of
  // size rows x cols.
  // [ e1,0 , e1,1 .. e1,n , e2,0 , e2,1 ... e2,n ]
  m = new T[rows*cols];
}


template <typename T>
T* matrix_<T>::operator [](uint index) {
  return (this->m)+   (this->colDim*(index));
}


template <typename T>
void matrix_<T>::printStirng () {
  std::cout << "\n" << "-------------------" << "\n";
  for (uint r=0;r<this->rowDim;r++) {
    for (uint c=0;c<this->colDim;c++) {
      std::cout << (*this)[r][c] << ",\t";
    }
    std::cout << " \n";
  }
  std::cout << "-------------------" << "\n";
}
