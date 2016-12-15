function menu1()
choice = 1;
adj_mat = [];
while choice ~= 5
    choice = input(['欢迎来到dijkstra算法求取最短路径系统！\n请选择：\n' ...
    '1.使用默认数据    2.输入数据   3.查看数据     4.求取路径' ...
    '    5.退出程序\n']);
    if choice == 1
        adj_mat = default_dat();
        fprintf('已启用默认数据\n');
    elseif choice == 2
        adj_mat = input_dat();
    elseif choice == 3
        disp(adj_mat);
    elseif choice == 4
        sta = input('请输入起始结点：');
        dst = input('请输入目的地：');
        if sta == dst
            fprintf('起始点与终点不能相同：\r\n');
        else
            [leng, path] = dijkstra(adj_mat, sta, dst);
            fprintf('最短路径为：%d\n', leng);
            k = length(path);
            fprintf('经过路径为：');
            for i = 1:1:k-1
                fprintf('%d --->',path(i));
            end
            fprintf('%d\n',path(k));
        end
    end
end