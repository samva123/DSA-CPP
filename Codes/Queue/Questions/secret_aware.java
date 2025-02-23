// import java.util.*;

// class Solution {
//     public int peopleAwareOfSecret(int n, int delay, int forget) {
//         final int MOD = 1_000_000_007;
//         int cur = 0;
//         int ans = 1;
//         Queue<int[]> delayQueue = new LinkedList<>();
//         Queue<int[]> forgetQueue = new LinkedList<>();
        
//         delayQueue.add(new int[]{1, 1});
//         forgetQueue.add(new int[]{1, 1});
        
//         for (int i = 1; i <= n; ++i) {
//             // Remove people who forget the secret
//             if (!forgetQueue.isEmpty() && forgetQueue.peek()[0] + forget == i) {
//                 int[] front = forgetQueue.poll();
//                 int no = front[1];
//                 ans = (ans - no + MOD) % MOD;
//                 cur = (cur - no + MOD) % MOD;
//             }

//             // People start sharing the secret after `delay` days
//             if (!delayQueue.isEmpty() && delayQueue.peek()[0] + delay == i) {
//                 int[] front = delayQueue.poll();
//                 cur = (cur + front[1]) % MOD;
//             }

//             // If there are new people aware of the secret, add them to the queues
//             if (cur > 0) {
//                 ans = (ans + cur) % MOD;
//                 delayQueue.add(new int[]{i, cur});
//                 forgetQueue.add(new int[]{i, cur});
//             }
//         }
//         return ans;
//     }
// }













import java.util.*;

class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final int MOD = 1_000_000_007;
        Queue<int[]> q = new LinkedList<>(); // Stores (day they start sharing, number of people)
        int ans = 1; // Initially, one person knows the secret
        q.add(new int[]{1, 1}); // (Start day, count of people)

        for (int i = 1; i <= n; ++i) {
            // Remove people who forget the secret
            while (!q.isEmpty() && q.peek()[0] + forget == i) {
                ans = (ans - q.poll()[1] + MOD) % MOD;
            }

            // Start sharing after `delay` days
            if (!q.isEmpty() && q.peek()[0] + delay == i) {
                int newPeople = ans; // All who currently know can start sharing
                q.add(new int[]{i, newPeople});
                ans = (ans + newPeople) % MOD;
            }
        }
        return ans;
    }
}
