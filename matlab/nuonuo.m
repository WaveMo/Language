%��ס�˿ڣ���λ�����ˣ�
numberOfPeople=[52.3 53.6 54.4 55.5];
%����������ֵ����λ����Ԫ��
grp=[225.84 234.71 245.32 313.72];
%�̶��ʲ�Ͷ���ܶ��λ����Ԫ��
investment=[160 161.03 226.92 271.76 ];
%�������Ʒ�����ܶ��λ����Ԫ��
retailSales=[62.49 67.04 77.01 101.5];
%��������˾���֧�����루��λ��Ԫ��
income=[36344 33355 35719 38688];
%�ط���������λ����Ԫ��
localFinance=[38.81 48.82 50.03 60.86];
%���������Ŀ�����ݣ�
area=[100 110 120 130];

%��������������������
input_test=[58.1 378.8 334.29 209.94 42330 74.67];
output_test=14;

%�������ݾ���
inputData=[numberOfPeople; grp; investment; retailSales; income; localFinance];
%Ŀ�꣨Ԥ�⣩���ݾ���
outputData=area;


%��ѵ�����е��������ݾ����Ŀ�����ݾ�����й�һ������
[pn, inputStr] = mapminmax(inputData);
[tn, outputStr] = mapminmax(outputData);

%����BP������
net = newff(pn, tn, [6 7 1], {'purelin', 'logsig', 'purelin'}, 'trainlm');



%�����ѧϰ����
net.trainParam.lr = 0.1;
%���ѵ������
net.trainParam.epochs = 5000;
%ѵ����������Ŀ�����
net.trainParam.goal = 0.000001;
%��������������6�ε�����û�仯����matlab��Ĭ����ֹѵ����Ϊ���ó���������У�����������ȡ����������
net.divideFcn = '';

%��ʼѵ������
net = train(net, pn, tn);

%ʹ��ѵ���õ����磬����ѵ���������ݶ�BP������з���õ�����������
answer = sim(net, pn)

%����һ��
answer1 = mapminmax('reverse', answer, outputStr)






