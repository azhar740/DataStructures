//Even number at even index and odd element at odd index

void arrangeOddAndEven(int arr[], int n)
{
   int oddInd = 1;
    int evenInd = 0;
    while (true)
    {
        while (evenInd < n && arr[evenInd] % 2 == 0)
            evenInd += 2;
              
        while (oddInd < n && arr[oddInd] % 2 == 1)
            oddInd += 2;
              
        if (evenInd < n && oddInd < n)
            swap (arr[evenInd], arr[oddInd]);
              
        else
            break;
    }
}
