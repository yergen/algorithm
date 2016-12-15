%isln函数接受2个参数，第一个为数组，第二个为数字，函数的功能为查看数字是否在数组中。
%函数的返回值为0或者1,1代表数字在数组中出现过，0代表并未出现。
function count = isln(array, num)
k = length(array);
count = 0;
for j = 1:1:k
    if array(j) == num;
        count = 1;
    end
end
