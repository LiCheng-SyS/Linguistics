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
using System.Threading;
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
                var headers = new Dictionary<string, string>() {
{ "Connection", "keep-alive" },
{ "sec-ch-ua", "\"Not?A_Brand\";v=\"8\", \"Chromium\";v=\"108\", \"Microsoft Edge\";v=\"108\"" },
{ "sec-ch-ua-mobile", "?0" },
{ "sec-ch-ua-platform", "\"Windows\"" },
{ "Upgrade-Insecure-Requests", "1" },
{ "User-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36 Edg/108.0.1462.54" },
{ "Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9" },
{ "Sec-Fetch-Site", "none" },
{ "Sec-Fetch-Mode", "navigate" },
{ "Sec-Fetch-User", "?1" },
{ "Sec-Fetch-Dest", "document" },
{ "Accept-Language", "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6" },
{ "Cookie", "qi5=1gp6y882c6a79%3AKqAt.owbeg.Fhqe2RRhT; fs=rmrde4; __gads=ID=951776eef778ecf8:T=1670815378:S=ALNI_MZGhQ20T9x7LkZYUBaoTq-k99QzWA; _gcl_au=1.1.1746927965.1670815380; afUserId=1a4b6e67-181b-4dfa-9f6d-6c6f99b00bc2-p; _lr_env_src_ats=false; pbjs-unifiedid=%7B%22TDID%22%3A%22fab522e8-4ef9-4b66-8ff7-1fd113fd6efb%22%2C%22TDID_LOOKUP%22%3A%22FALSE%22%2C%22TDID_CREATED_AT%22%3A%222022-12-12T03%3A23%3A44%22%7D; app_session_id=2188b899-4cf1-4140-b085-bab9284af770; akv=%7B%7D; __gpi=UID=00000b8e5b165fc0:T=1670815378:RT=1672797045:S=ALNI_MYu4EEdaWrt1Xje9KXBggxpqz-K7Q; _gid=GA1.2.225706584.1672797047; _lr_retry_request=true; AF_SYNC=1672797053699; cnx_userId=2aab512f3d1e436ba1116f48d4860d11; cto_bundle=rgG5MV83OEpxS01DU1pReDltdTczVDVOYUU1ZFFHZk11ZmNIS1FEVzROTE0zM0Exb3RxYmhycml3ZEJyWGp4a1dUTDF2enBQMXdNWGFGNjg3VEJucXJRdnU3TmpGJTJCc1JpNktvJTJGaXdXJTJGNnFBZnVkUUc2ZXJ2T2k0Yklvc3FCZDg3cEprMw; cto_bidid=YNqqUV9vVU52QnhnZ3d4ODZHa2xRdUhOQkd5MVphQW1ZVlhMMkRpdXVwZFNuOHYlMkJkOFZDeDNCaGdGQno3VGpva1MlMkJvTmN2Q0Z5OEdWN0Q1NVZIdzJGcnZpelElM0QlM0Q; _lr_geo_location=CN; __cf_bm=Avj.tOr9dU0RVp6yAJTs0.meaTHYFS_cJi2DZRKhS.c-1672798991-0-AR8IcCoRjrqR+OPRBtSMeJe9CgqfOIjiyKt6GdPYtlLcLQ48VuTG2cW610cdgSlZQxeRpGJShgMP+JQKEHQypBI=; cf_chl_rc_m=1; cf_chl_2=1ef60d3212548be; cf_clearance=3gu8im4d5HsfJaQLlp_xOMX.HzJurGFActrhuYCUEMk-1672799064-0-250; qtkn=DtznQBYyy8AE2parqZxjgK; __cfruid=d2cc10ff59bb4611d0b0f3a4e9d0c87fec5d12b5-1672799065; _cfuvid=_8wjHEBUVpyj0ERB13Cet1FY_d4jOTaKKLM5EIbDf2Y-1672799065642-0-604800000; session_landing_page=Sets%2Fshow; _pbjs_userid_consent_data=3524755945110770; qmeasure__persistence=%7B%2228%22%3A%2200000100%22%2C%2233%22%3A%2200000100%22%2C%2237%22%3A%2200001000%22%7D; _gat_UA-1203987-1=1; _ga_BGGDEZ0S21=GS1.1.1672797044.3.1.1672799076.0.0.0; _ga=GA1.1.1287302664.1670815379; hide-fb-button=1" },

};
                var resultHtml = url.WithHeaders(headers).GetAsync().ReceiveString().Result;
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
                    if (res.IndexOf("<!DOCTYPE html>") !=0) return;

                    IList<Word_InfoModel> reslist = await _Info_Word.GetWordInfoAsync(res);
                    if (reslist.Count == 0) return;
                    _word_info.Enqueue(reslist);
                    foreach (var queitem in _word_info)
                    {      
                            Task.Run(async () =>
                            {
                                foreach (var item in queitem)
                                {
                                    if (!await _Info_Word.CheckExistWordInfoAsync(item.Text))
                                    {
                                        if (await _Info_Word.InSertWordInfoAsync(item))
                                        {
                                            ShowMessage($" ManagedThreadId  :{Thread.CurrentThread.ManagedThreadId } " + item.Text + " " + item.Translate + "  " + item.pos);

                                        }
                                        else
                                        {
                                            ShowMessage($"{item.Text}  {item.Translate} {item.pos}   fail");
                                            return;
                                        }
                                    }
                                }
                            });
                        
                                      
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

