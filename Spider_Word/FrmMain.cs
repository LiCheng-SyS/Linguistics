using Flurl.Http;
using Spider_Word.Word_IService;
using Spider_Word.Wrod_Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Spider_Word
{
    public partial class FrmMain : Form
    {
        private readonly IWord_Info _Info_Word;

        private Queue<IList<Word_InfoModel>> _word_info=new  Queue<IList<Word_InfoModel>>();
        public FrmMain()
        {
            InitializeComponent();
        }

        public FrmMain(IWord_Info info_word)
        {
            _Info_Word = info_word;
            InitializeComponent();

        }

    

        public delegate void ListViewDelegate<T>(T obj);

        public static string DownloadFile(string url)
        {
            try
            {
                var dic1 = new Dictionary<string, string>() {
{ "Connection", "keep-alive" },
{ "sec-ch-ua", "\"Not?A_Brand\";v=\"8\", \"Chromium\";v=\"108\", \"Microsoft Edge\";v=\"108\"" },
{ "sec-ch-ua-mobile", "?0" },
{ "sec-ch-ua-platform", "\"Windows\"" },
{ "Upgrade-Insecure-Requests", "1" },
{ "User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36 Edg/108.0.1462.46" },
{ "Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9" },
{ "Sec-Fetch-Site", "none" },
{ "Sec-Fetch-Mode", "navigate" },
{ "Sec-Fetch-User", "?1" },
{ "Sec-Fetch-Dest", "document" },
    { "Cookie","__cf_bm=lO9e5U.zIA8_8Fw90wmiutqu1tYYazknPeyWM1GfkmU-1670815073-0-ASDtbhKmNV7osSA4fkSgeVbyky5NCuY9BJSOmM6XlgxQmQMq/gXnpSYeHJwV902zCaVesCYxg85Ci4+2Wx5Ntcc=; _cfuvid=gEIof52oR9aDGDEdoIoyUMMY6Z3XjvwlUs5ZcdI89D8-1670815074175-0-604800000; cf_chl_rc_m=1; cf_chl_2=348f9605eb06360; cf_clearance=eHhLwaXCejpwlbC3b9.o5ROa06C91B9sqmbcj2d7QT4-1670815372-0-250; qi5=1gp6y882c6a79%3AKqAt.owbeg.Fhqe2RRhT; qtkn=MZzZW4NvR69Gjd4kgCutc2; fs=rmrde4; app_session_id=730b1a48-82fa-4372-90f9-2b3a528342e8; akv=%7B%7D; qmeasure__persistence=%7B%2228%22%3A%2200000100%22%2C%2233%22%3A%2200000100%22%7D; __cfruid=903167041fa0269b51292ecf4af13240c964a9aa-1670815376; session_landing_page=Sets%2Fshow; __gads=ID=951776eef778ecf8:T=1670815378:S=ALNI_MZGhQ20T9x7LkZYUBaoTq-k99QzWA; __gpi=UID=00000b8e5b165fc0:T=1670815378:RT=1670815378:S=ALNI_MYu4EEdaWrt1Xje9KXBggxpqz-K7Q; _gcl_au=1.1.1746927965.1670815380; _gid=GA1.2.913632697.1670815381; hide-fb-button=1; afUserId=1a4b6e67-181b-4dfa-9f6d-6c6f99b00bc2-p; AF_SYNC=1670815388270; _pbjs_userid_consent_data=3524755945110770; _lr_retry_request=true; _lr_env_src_ats=false; pbjs-unifiedid=%7B%22TDID%22%3A%22fab522e8-4ef9-4b66-8ff7-1fd113fd6efb%22%2C%22TDID_LOOKUP%22%3A%22FALSE%22%2C%22TDID_CREATED_AT%22%3A%222022-12-12T03%3A23%3A44%22%7D; _ga_BGGDEZ0S21=GS1.1.1670815380.1.1.1670815454.0.0.0; _ga=GA1.2.1287302664.1670815379; cto_bundle=enuzRV83OEpxS01DU1pReDltdTczVDVOYUU1RU9ER1JpdmpWN2gyak54QU5EWU5vUU1JWGtrSlNJbmJRVVFVSXhYUWltdThqcVB2ZURHeld6Vk9QaiUyRmxFRWUlMkZudjNPRHNYMVF3cSUyRjM2RVBQRUR2SFJVdzdMdW1oakM0MWpTZGRhbmFDeg; cto_bidid=Vj2DVF9vVU52QnhnZ3d4ODZHa2xRdUhOQkd5MVphQW1ZVlhMMkRpdXVwZFNuOHYlMkJkOFZDeDNCaGdGQno3VGpva1MlMkJvTkMlMkZXbzklMkI1N0VVMTVlZjlwQ0cwJTJGOFElM0QlM0Q; _lr_geo_location=CN"} };
                var resultHtml = url.WithHeaders(dic1).GetAsync().ReceiveString().Result;
                return resultHtml;
            }
            catch (Exception ex)
            {
                return ex.Message;
            }
        }

        private void textUrL_KeyDown(object sender, KeyEventArgs e)
        {
            var val = textUrL.Text.Trim();
            textUrL.Text = string.Empty;
            Task.Run(async () =>
            {
                if (!string.IsNullOrEmpty(val) && e.KeyValue == 13)
                {
                    string res = DownloadFile(val);
                    IList<Word_InfoModel> reslist = await _Info_Word.GetWordInfoAsync(res);
                    if (reslist.Count == 0) return;
                    _word_info.Enqueue(reslist);
                    foreach (var queitem in _word_info)
                    {
                        foreach (var item in queitem)
                        {
                            await Task.Run(async () =>
                            {
                                if (!await _Info_Word.CheckExistWordInfoAsync(item.Text))
                                {
                                    if (await _Info_Word.InSertWordInfoAsync(item))
                                    {
                                        ShowMessage(item.Text + " " + item.Translate + "  " + item.pos);
                                        queitem.Remove(item)
                                    }
                                    else
                                    {
                                        ShowMessage($"{item.Text}  {item.Translate} {item.pos}   fail");
                                        return;
                                    }
                                }
                            });
                        }
                        _word_info.Dequeue();
                    }
              
                }
            });

        }



        private void ShowMessage(string msg)
        {
            if (InvokeRequired)
            {
                BeginInvoke(new ListViewDelegate<string>(ShowMessage), msg);
            }
            else
            {
                TextMsg.Text = ($"{DateTime.Now.ToString("yyyy / MM / dd HH: mm:ss ffffff")} ::  {msg}  \n***********************************************************************\n {TextMsg.Text}\n");
                if (TextMsg.Text.Length > 10000)
                {
                    TextMsg.Text = TextMsg.Text.Substring(0, 10000);
                }

            }
        }
    }


}

