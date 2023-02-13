​
//Method - 1: By Neetcode wale paaji
![Screenshot_2023-02-13_PageMarker](https://user-images.githubusercontent.com/83157814/218546359-66bb817a-db2b-4160-b66a-1ec52ed3c441.png)
![1](https://user-images.githubusercontent.com/83157814/218546502-e02f7464-89fe-4281-8c07-7eb439a8048d.jpg)
![2](https://user-images.githubusercontent.com/83157814/218546527-8dcc6af6-f395-48e1-ace5-b93991907f2b.jpg)


int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int l=-1, r=n;
        
        while(r>l+1) {
            int mid = l - (l-r)/2;
            
            //if possible answer (mid) is our answer, return answer.
            if(nums[mid]==target) {
                return mid;
            }
            
            //case when mid lies in the Left sorted array
            //l+1 because it takes care of the edge case when l = -1.
            else if(nums[mid] >= nums[l+1]) {
                if(target > nums[mid]) {
                    l = mid;   //No confusion: target lies in Right search space
                }
                 
                else if(target < nums[mid]) {   //confusion as target could be present in either of the search space
                    if(target > nums[l+1]) {
                        r = mid;
                    } 
                
                    else if(target < nums[l+1]) {
                        l = mid;
                    } 
                    //this else becomes important as equality condition pe r = mid ho rha tha and l+1 wale ke chance the ki wo search space se bahar chala jaata which we dont want as it could be our potential answer.
                    else {
                        return l+1;
                    }
                }
            }
            
            //mid lies in the right sorted array
            else {
                if(target < nums[mid]) {
                    r = mid;
                }
                
                else if(target > nums[mid]) {
                    if(target > nums[r-1]) {
                        r = mid;
                    } 
                    
                    else if(target < nums[r-1]) {
                        l = mid;
                    } 
                    
                    else {
                        return r-1;
                    }
                }
            }
        }
        
        return -1;
        
    }
                                               
                                               
//Method - 2:
                                               
    ![Screenshot 2023-02-13 232925](https://user-images.githubusercontent.com/83157814/218546637-72ba4e2f-ecc6-4b08-b3b1-f65658d73162.png)
                                               
                                               
                                               
  //Method - 3: Preferred
                                               
  ![3](https://user-images.githubusercontent.com/83157814/218547231-04f8fad9-c694-4b64-80f0-d7fca66e04fb.jpg)
                                             
    ![Screenshot (48)](https://user-images.githubusercontent.com/83157814/218547285-0b4c6c12-3527-45ab-a961-832d854219d6.png)
                                           
                                           
