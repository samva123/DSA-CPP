import java.util.*;

class Graph<T>{

    Map<T , List<Pair<T , Integer>>> adjList = new HashMap<>();
    Set<T>nodes  = new HashSet<>();

    void addEdge(T u , T v , int wt , boolean direction){
        nodes.add(u);
        nodes.add(v);
        adjList.putIfAbsent(v, new ArrayList<>());
        adjList.putIfAbsent(u, new ArrayList<>());

        if(direction){
            adjList.get(u).add(new Pair<>(v , wt));
        }else{
            adjList.get(u).add(new Pair<>(v,wt));
            adjList.get(v).add(new Pair<>(u,wt));

        }

    }

    void bfs(T src , Map<T,Boolean>vis){
        Queue<T>q = new LinkedList<>();

        q.add(src);
        vis.put(src, true);

        while(!q.isEmpty()){
            T node  = q.poll();
            System.out.print(node + " ");

            for(var nbr : adjList.getOrDefault(node , new ArrayList<>()) ){
                var nbrf = nbr.first;

                if(!vis.getOrDefault(nbrf,false)){
                    vis.put(nbrf , true);
                    q.add(nbrf);
                }
            }
        }


    }
}

class Pair<U,V>{
    U first;
    V second;

    Pair(U f , V s){
        first = f;
        second  = s;
    }
}

class Main{
    public static void main(String[] args){
        Graph<Character>g = new Graph<>();

        g.addEdge('a', 'b', 5, true);
        g.addEdge('a', 'c', 10, true);
        g.addEdge('b', 'c', 20, true);
        g.addEdge('e', 'f', 50, true);
        g.addEdge('f', 'd', 50, true);

        Map<Character, Boolean> vis = new HashMap<>();

        int count = 0;

       
        for (Character node : g.nodes) {
            if (!vis.getOrDefault(node, false)) {
                count++;
                g.bfs(node, vis);
            }
        }
    }

}