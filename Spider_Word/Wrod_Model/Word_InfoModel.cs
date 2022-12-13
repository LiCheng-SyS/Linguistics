using System;
using System.Collections.Generic;
using System.Text;

namespace Spider_Word.Wrod_Model
{
    public class Word_InfoModel
    {
        public int ID { get; set; }
        public string Text { get; set; }
        public string Translate { get; set; }

        public string Status { get; set; }

        public int Phone { get; set; }

        public string bookid { get; set; }

        /// <summary>
        /// 词性
        /// </summary>
        public string pos { get; set; }
    }
}


//IService