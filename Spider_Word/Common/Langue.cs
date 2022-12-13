using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace Spider_Word.Common
{
    public class Langue
    {

        public static string LangueSelect(string content)
        {
            // 判断韩语
            if (Regex.IsMatch(content, @"^[\uac00-\ud7ff]+$"))
            {
                return "ko_kr";
            }

            // 判断日语
            if (Regex.IsMatch(content, @"^[\u0800-\u4e00]+$"))
            {
                return "ja_jp";
            }

            // 判断中文
            if (Regex.IsMatch(content, @"^[\u4e00-\u9fa5]+$")) // 
            {
                return "zh-cn";
            }

            // 判断英语
            if (Regex.IsMatch(content, @"^[A-Za-z]+$")) // 英语
            {
                return "en-us";
            }
            return "";
        }

    }
}
