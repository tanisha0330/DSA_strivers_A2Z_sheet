/*iterative approach*/
vector<int> getAlternates(vector<int> &arr) {
        vector <int> res ; 
       for (int i=0 ; i<(arr.size()+1)/2 ; i++)
       {
           res.push_back(arr[2*i]); 
       }
        return res ; 
    }

/*recursive approach*/

void solve(vector<int>& arr, int i, vector<int>& res) 
  {
      if (i >= arr.size()) return;
  
      res.push_back(arr[i]);
      solve(arr, i + 2, res);
  }

vector<int> getAlternates(vector<int>& arr) 
  {
      vector<int> res;
      solve(arr, 0, res);
      return res;
  }





