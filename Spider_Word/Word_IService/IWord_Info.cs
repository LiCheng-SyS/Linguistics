using Spider_Word.Wrod_Model;
using System;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace Spider_Word.Word_IService
{
   public interface IWord_Info
    {
        Task<IList<Word_InfoModel>> GetWordInfoAsync(string dom);

        Task<bool> CheckExistWordInfoAsync(string word);

        Task<bool> InSertWordInfoAsync(Word_InfoModel word);
    }
}
