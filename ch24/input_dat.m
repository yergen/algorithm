%让用户输入数据并生成邻接矩阵并返回
function adj_mat = input_dat()
length = input('请输入结点数量： ');
adj_mat = zeros(length);
for i = 1:1:length
    for j = i:1:length
        if i ~= j
            fprintf('请输入结点%d到结点%d的长度（没有则输入0）',i, j)
            adj_mat(i,j) = input(':');
            if adj_mat(i,j) == 0
                adj_mat(i,j) = inf;
            end
            adj_mat(j,i) = adj_mat(i,j);
        end
    end
end