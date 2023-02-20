using Spider_Word.Word_IService;
using Spider_Word.Wrod_Model;
using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;
using HtmlAgilityPack;
using Microsoft.Extensions.Configuration;
using Spider_Word.Common;
using MySql.Data.MySqlClient;
using System.Data;
using System.Linq;
using System.Text.RegularExpressions;

namespace Spider_Word.Wrod_Service
{
    public class Word_InfoDAL : IWord_Info
    {
        private readonly IConfiguration _configuration;
        private MySQLHelper _mySQLHelper;
        public Word_InfoDAL(IConfiguration configuration)
        {
            _configuration = configuration;
            var connectionString = _configuration.GetConnectionString("word_dateDb");
            _mySQLHelper = new MySQLHelper(connectionString);
        }

        public async Task<bool> InSertWordInfoAsync(Word_InfoModel wordmodel)
        {
            try
            {
                StringBuilder strSql = new StringBuilder();
                strSql.Append("INSERT INTO  Korean_kr (");
                strSql.Append("bookID, status, headWord, phone, tranCN, hiragana, pos)");
                strSql.Append(" values (");
                strSql.Append("@bookID, @status, @headWord, @phone, @tranCN, @hiragana, @pos)");
                strSql.Append(";select @@IDENTITY");

                MySqlParameter[] parameters = {
                    new MySqlParameter("@bookID", wordmodel.bookid),
                    new MySqlParameter("@status", wordmodel.Status),
                    new MySqlParameter("@headWord", wordmodel.Text),
                    new MySqlParameter("@phone", wordmodel.Phone),
                    new MySqlParameter("@tranCN", wordmodel.Translate),
                    new MySqlParameter("@hiragana", "".Trim() ),
                    new MySqlParameter("@pos",  wordmodel.pos)
                };
                return await Task.Run(() => { return _mySQLHelper.ExecuteNonQuery(strSql.ToString(), parameters) == 1 ? true : false; });
            }
            catch (Exception ex)
            {
                return await Task.Run(() => { return false; });
            }

        }


        public async Task<bool> CheckExistWordInfoAsync(string word)
        {
            string str = $"SELECT  count(1) FROM word_date.Korean_kr WHERE headWord ='{word}'";
            var res = Convert.ToInt32(_mySQLHelper.ExecuteDataTable(str).Rows[0][0]) >=1 ? true : false;
            return await Task.Run(() => { return res; });
        }

        public async Task<IList<Word_InfoModel>> GetWordInfoAsync(string dom)
        {
            try
            {
                var list = new List<Word_InfoModel>();
                HtmlDocument htmlDocument = new HtmlDocument();
                htmlDocument.LoadHtml(dom);
                var nodehead = htmlDocument.DocumentNode.SelectNodes("//div[@class='SetPage-titleWrapper']");
                var nodes = htmlDocument.DocumentNode.SelectNodes("//div[@class='SetPageTerm-contentWrapper']");
                foreach (HtmlNode item in nodes)
                {
                    var nodes2 = item.SelectSingleNode("div/div[1]/div[1]/a[1]");

                    var nodes3 = item.SelectSingleNode("div/div[2]/div[1]/a[1]");
                    if (nodes2 != null && nodes3 != null)
                    {
                        //填充词性
                        string indextext = nodehead.FirstOrDefault((t) => true)?.InnerText;

                        Regex rx = new Regex("[\u4e00-\u9fa5]+");
                        var ansstr =  rx.Match(indextext).Value;
                        list.Add(new Word_InfoModel
                        {
                            Status = "0",
                            Phone = 0,
                            bookid = Langue.LangueSelect(nodes2.InnerText),
                            pos = ansstr,
                            Text = nodes2.InnerText,
                            Translate = nodes3.InnerText
                        });
                    }
                }
                return await Task.Run(() => { return list; });
            }
            catch (Exception ex)
            {
                return await Task.Run(() => { return new List<Word_InfoModel>(); });
            }    
        }


    }
}
