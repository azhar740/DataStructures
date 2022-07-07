[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
}

for_each(v.begin(), v.end(), [] (int i){
  cout << i << " ";
});

vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};
vector<int>::iterator p = find_if(v.begin(), v.end(), [](int i){
  return i > 4;
});
cout << *p << endl; // will print 5
