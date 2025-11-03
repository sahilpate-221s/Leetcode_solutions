class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length())return false;
        
        String str = s + s;

        boolean val= str.contains(goal);
        return val;
    }
}