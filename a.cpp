#include <iostream>
#include <string>


using namespace std;


int main()
{
    string a = "张少爷";
    string ans;
    for (int i = 0; i < a.size();++i)
    {
        int t = a[i];
        string cur=
    }
}
/**
	 * 
	 * 将String转换成unicode编码格式
	 * @param str
	 * @return String
	 * @throws
	 */
public
static String unicodeEncoding(String str)
{
    if (str == null || str.trim().length() == 0)
    {
        return EMPTY;
    }
    StringBuffer unicodeBytes = new StringBuffer();
    for (int byteIndex = 0; byteIndex < str.length(); byteIndex++)
    {
        //字符-Unicode-16进制字符串形式返回
        String hexB = Integer.toHexString(str.charAt(byteIndex));
        unicodeBytes.append("\\u");
        //一定补足4个16进制位--即2个字节
        if (hexB.length() <= 2)
        {
            unicodeBytes.append("00");
        }
        unicodeBytes.append(hexB);
    }
    return unicodeBytes.toString();
}