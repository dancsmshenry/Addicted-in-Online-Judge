class Solution {
    public boolean isPalindrome(String s){
        //原来java里面访问字符串是用charAt的，不能用[]....
        int left = 0, right = s.length() - 1;

        //character.isletterordigit是判断当前的字符是不是数字或字母
        //charactre.tolowercase是把当前的字母转换为小写
        while (left < right){
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))){
                left ++ ;
            }
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))){
                right -- ;
            }
            if (left < right) {
                if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))){
                    return false;
                }
                left ++ ;
                right -- ;
            }
        }

        return true;
    }
}