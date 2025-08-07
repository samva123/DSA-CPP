// class Solution {
//     public String customSortString(String order, String s) {
      
//         int N = s.length();
//         Character[] result = new Character[N];
//         for (int i = 0; i < N; i++) {
//             result[i] = s.charAt(i);
//         }

        
//         Arrays.sort(result, (c1, c2) -> {
//             return order.indexOf(c1) - order.indexOf(c2);
//         });

//         String resultString = "";
//         for (Character c: result) {
//             resultString += c;
//         }
//         return resultString;
//     }
// }
















// class Solution {
//     public String customSortString(String order, String s) {

//         Map<Character, Integer> freq = new HashMap<>();


//         int N = s.length();
//         for (int i = 0; i < N; i++) {
//             char letter = s.charAt(i);
//             freq.put(letter, freq.getOrDefault(letter, 0) + 1);
//         }


//         int K = order.length();
//         StringBuilder result = new StringBuilder();
//         for (int i = 0; i < K; i++) {
//             char letter = order.charAt(i);
//             while (freq.getOrDefault(letter, 0) > 0) {
//                 result.append(letter);
//                 freq.put(letter, freq.get(letter) - 1);
//             }
//         }

//         for (char letter : freq.keySet()) {
//             int count = freq.get(letter);
//             while (count > 0) {
//                 result.append(letter);
//                 count--;
//             }
//         }

//         return result.toString();
//     }
// }