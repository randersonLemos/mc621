
int main(){

  int count = 0;

  while(true){
    count++;
    int n, f;
    std::cin >> n >> f;
    
    if( n==0 || f == 0 )
      break;

    long int value, bill = 0;
    for( int i=0; i<n; i++ )
    {
      std::cin >> value;
      bill += value;
    }
    
    std::cout << "Bill #" << count << " costs " << bill << ": each friend should pay " <<  bill/f << std::endl;

  }
  return 0;
}
