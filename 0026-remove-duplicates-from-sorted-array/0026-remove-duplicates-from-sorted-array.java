class Solution {
    public int removeDuplicates(int[] nums) {
        TreeSet<Integer>s = new TreeSet<>();
        for(int a: nums)s.add(a);
        int i = 0 ;
        for(int b: s){
            nums[i] = b;
            i++;
        }
        return s.size();
    }
}