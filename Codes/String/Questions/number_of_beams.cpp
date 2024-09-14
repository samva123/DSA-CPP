class Solution {
public:

    int cdevices(string&binary){
        int c=0;
        for(int i = 0 ; i < binary.length() ; i++){
            int b = binary[i];
             c += b-'0';
        }
       
        return c;
        
    }
    
    int numberOfBeams(vector<string>& bank) {
        vector <int> devices;
        for(auto row:bank)
          devices.push_back(cdevices(row));
          int beams =0;
          for(int i = 0 ; i<devices.size() ;++i){
              int j = i+1;
              while( j < devices.size()){
                  beams += devices[i]*devices[j];
                  if(devices[j] == 0){
                  j++;
                  }
                  else{
                  break;
                  }
              }
          }
          return beams;

        

        
    }
}; 