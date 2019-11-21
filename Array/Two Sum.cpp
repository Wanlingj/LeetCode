class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //Key is the number and value is its index in the vector.
	    unordered_map<int, int> hash;
	    vector<int> result;
	    for (int i = 0; i < nums.size(); i++) {
		    int numberToFind = target - nums[i];

            //if numberToFind is found in map, return them
		    if (hash.find(numberToFind) != hash.end()) { // if found
                    //+1 because indices are NOT zero based
			    result.push_back(hash[numberToFind] );//push back index [numberToFind, index]
			    result.push_back(i); //push back index i itself		
                
			    return result;// when found return the result
		    }

            //number was not found. Put it (nums[i]) in the map.
		    hash[nums[i]] = i;
	    }
	    return result;
    }
    
};
