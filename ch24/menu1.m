function menu1()
choice = 1;
adj_mat = [];
while choice ~= 5
    choice = input(['��ӭ����dijkstra�㷨��ȡ���·��ϵͳ��\n��ѡ��\n' ...
    '1.ʹ��Ĭ������    2.��������   3.�鿴����     4.��ȡ·��' ...
    '    5.�˳�����\n']);
    if choice == 1
        adj_mat = default_dat();
        fprintf('������Ĭ������\n');
    elseif choice == 2
        adj_mat = input_dat();
    elseif choice == 3
        disp(adj_mat);
    elseif choice == 4
        sta = input('��������ʼ��㣺');
        dst = input('������Ŀ�ĵأ�');
        if sta == dst
            fprintf('��ʼ�����յ㲻����ͬ��\r\n');
        else
            [leng, path] = dijkstra(adj_mat, sta, dst);
            fprintf('���·��Ϊ��%d\n', leng);
            k = length(path);
            fprintf('����·��Ϊ��');
            for i = 1:1:k-1
                fprintf('%d --->',path(i));
            end
            fprintf('%d\n',path(k));
        end
    end
end