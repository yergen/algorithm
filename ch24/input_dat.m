%���û��������ݲ������ڽӾ��󲢷���
function adj_mat = input_dat()
length = input('�������������� ');
adj_mat = zeros(length);
for i = 1:1:length
    for j = i:1:length
        if i ~= j
            fprintf('��������%d�����%d�ĳ��ȣ�û��������0��',i, j)
            adj_mat(i,j) = input(':');
            if adj_mat(i,j) == 0
                adj_mat(i,j) = inf;
            end
            adj_mat(j,i) = adj_mat(i,j);
        end
    end
end