// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Collections;
// import java.util.List;
// public class jobScheduling {
//     static class pair{
//         int delay;
//         int value;
//         pair(int delay ,int value){
//             this.delay = delay;
//             this.value = value;
//         }
//         @Override
//         public String toString(){
//             return  delay + ",  " + value;
//         }
//     }
//     public static void main(String[] args) {
//         int[] delay = {3,1,2,4,2};
//         int[] value = {10,80,80,80,80};
//         List<pair> l = new ArrayList<>();
//         int max = 0 ;
//         for(int i = 0 ; i < delay.length ; i++){
//             max = Math.max(delay[i] , max);
//             l.add(new pair(delay[i], value[i]));
//         }
//         Collections.sort(l ,(a,b) -> b.value - a.value);
//         System.out.println(l);
//         int[] result = new int[max+1];
//         for(pair temp : l){
//             while(temp.delay>=1){
                
//                 if(result[temp.delay]!= 0 ){
//                     temp.delay--;
//                 }
//                 else{
//                     result[temp.delay] = temp.value;
//                     break;
//                 }
//             }    
//         }
//         System.out.println(Arrays.toString(result));
//     }
    
// }