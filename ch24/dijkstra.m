function [leng, path] = dijkstra(adj_mat, sta, dst)
m = length(adj_mat);
lengs = linspace(0,0,m);
paths = linspace(0,0,m);
know = linspace(0,0,m);
know(1) = sta;
k = 1;
for i = 1:1:m
    if i~= sta
        lengs(i) = adj_mat(sta, i);
        if lengs(i) ~= inf
            paths(i) = sta;
        end
    end
end
index = 1;
for i = 1:1:m
    if i ~= sta
        min = inf;
        for j = 1:1:m
            count = isln(know,j);
            if count == 0 && lengs(j) <= min
                k = j;
                min = lengs(j);
            end
        end
        know(index) = k;
        index = index + 1;
        for j = 1:1:m
            count = isln(know, j);
            if count == 0 && (lengs(i) + adj_mat(i,j)) < lengs(j)
                  lengs(j) = lengs(i) + adj_mat(i,j);
              paths(j) = i;
            end
        end
    end
end
leng = lengs(dst);
k = dst;
j = 1;
path = dst;
while paths(k) ~= sta
    k = paths(k);
    path = sym([k path]);
end
path = [sta path];
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            