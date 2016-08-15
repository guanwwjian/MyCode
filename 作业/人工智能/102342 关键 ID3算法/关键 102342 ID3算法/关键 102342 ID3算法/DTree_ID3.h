using System;
using System::Collections::Generic;
using System::Text;
using System::Data;
using System::Collections;
using System::Windows::Forms;
namespace �ؼ�102342ID3�㷨
{
	public class DTree_ID3
    {
        private DataTable mSamples;
        private string mTargetAttribute = "result";
        public Entropy en = new Entropy();
        public TreeNode roots;
        private Attribute getBestAttribute(DataTable samples, Attribute[] attributes, string attributeSelectionMethod)
        {
            double maxGain = 0.0;
            Attribute result = null;

            if (attributeSelectionMethod == "gain")
            {
                foreach (Attribute attribute in attributes)
                {
                    double aux = en.gain(samples, attribute);
                    if (aux > maxGain)
                    {
                        maxGain = aux;
                        result = attribute;
                    }
                }
            }
            else if (attributeSelectionMethod == "gainRatio")
            {
                foreach (Attribute attribute in attributes)
                {
                    double aux = en.gainRatio(samples, attribute);
                    if (aux > maxGain)
                    {
                        maxGain = aux;
                        result = attribute;
                    }
                }
            }
            return result;
        }

        /// <summary>
        /// �ж��������Ƿ�����ͬһ��,���򷵻ش�����ֵ�����򷵻�null
        /// </summary>
        /// <param name="samples"></param>
        /// <param name="targetAttribute"></param>
        /// <returns></returns>
        private string allSamplesSameClass(DataTable samples, string targetAttribute)
        {
            string targetValue = samples.Rows[0][targetAttribute].ToString();
            for (int i = 1; i < samples.Rows.Count; i++)
            {
                if (!targetValue.Equals(samples.Rows[i][targetAttribute].ToString()))
                    return null;
            }

            return targetValue;
        }

        ///// <summary>
        ///// Retorna true caso todos os exemplos da amostragem s�o negativos
        ///// </summary>
        ///// <param name="samples">DataTable com as amostras</param>
        ///// <param name="targetAttribute">Atributo (coluna) da tabela a qual ser?verificado</param>
        ///// <returns>True caso todos os exemplos da amostragem s�o negativos</returns>
        //private bool allSamplesNegatives(DataTable samples, string targetAttribute)
        //{
        //    foreach (DataRow row in samples.Rows)
        //    {
        //        if ((bool)row[targetAttribute] == true)
        //            return false;
        //    }

        //    return true;
        //}

        /// <summary>
        /// Retorna uma lista com todos os valores distintos de uma tabela de amostragem
        /// </summary>
        /// <param name="samples">DataTable com as amostras</param>
        /// <param name="targetAttribute">Atributo (coluna) da tabela a qual ser?verificado</param>
        /// <returns>Um ArrayList com os valores distintos</returns>
        private ArrayList getDistinctValues(DataTable samples, string targetAttribute)
        {
            ArrayList distinctValues = new ArrayList(samples.Rows.Count);

            foreach (DataRow row in samples.Rows)
            {
                if (distinctValues.IndexOf(row[targetAttribute]) == -1)
                    distinctValues.Add(row[targetAttribute]);
            }

            return distinctValues;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="samples"></param>
        /// <param name="targetAttribute"></param>
        /// <returns></returns>
        private object getMostCommonValue(DataTable samples, string targetAttribute)
        {
            ArrayList distinctValues = getDistinctValues(samples, targetAttribute);
            int[] count = new int[distinctValues.Count];

            foreach (DataRow row in samples.Rows)
            {
                int index = distinctValues.IndexOf(row[targetAttribute]);
                count[index]++;
            }

            int MaxIndex = 0;
            int MaxCount = 0;

            for (int i = 0; i < count.Length; i++)
            {
                if (count[i] > MaxCount)
                {
                    MaxCount = count[i];
                    MaxIndex = i;
                }
            }

            return distinctValues[MaxIndex];
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="samples"></param>
        /// <param name="targetAttribute"></param>
        /// <returns></returns></returns?>
        private TreeNode buildTree(DataTable samples, string targetAttribute, Attribute[] attributes, string attributeSelectionMethod)
        {
            TreeNode temp = new TreeNode();

            //  if samples�е�Ԫ�鶼��ͬһ��C then
            string c = allSamplesSameClass(samples, targetAttribute);
            if ( c!=null)   //����N��ΪҶ�ڵ㣬����C���
                return new TreeNode(new Attribute(c).AttributeName+c);
            

            //if attributesΪ�� then
            if (attributes.Length == 0) //����N��ΪҶ�ӽڵ㣬���ΪD�еĶ����ࣻ�������
                return new TreeNode(new Attribute(getMostCommonValue(samples, targetAttribute)).AttributeName);

            //����Ŀ�����Ե���Ϣ��
            mTargetAttribute = targetAttribute;
            en.getEntropy(samples);

            //�ҳ���õķ������ԣ�����Ϣ������
            Attribute bestAttribute = getBestAttribute(samples, attributes, attributeSelectionMethod);

            //���Ϊ�ڵ�root
            DTreeNode root = new DTreeNode(bestAttribute);
            temp.Text=bestAttribute.AttributeName;

            DataTable aSample = samples.Clone();

            //(10) ΪbestAttribute��ÿ�����value����Ԫ�鲢��ÿ�����ֲ�������
            foreach (string value in bestAttribute.values)
            {
                // Seleciona todas os elementos com o valor deste atributo				
                aSample.Rows.Clear();
                //aSampleΪ�������value�ļ��ϣ���һ�����֣���֧��
                DataRow[] rows = samples.Select(bestAttribute.AttributeName + " = " + "'" + value + "'");

                foreach (DataRow row in rows)
                {
                    aSample.Rows.Add(row.ItemArray);
                }

                //ɾ����������
                ArrayList aAttributes = new ArrayList(attributes.Length - 1);
                for (int i = 0; i < attributes.Length; i++)
                {
                    if (attributes[i].AttributeName != bestAttribute.AttributeName)
                        aAttributes.Add(attributes[i]);
                }


                //���aSampleΪ�գ���һ����Ҷ���ڵ�N�����ΪaSample�еĶ�����
                if (aSample.Rows.Count == 0)
                {
                    //return new TreeNode(new Attribute(getMostCommonValue(aSample, targetAttribute)).AttributeName);

                    TreeNode leaf = new TreeNode();
                    //leaf.Text = (new Attribute(getMostCommonValue(aSample, targetAttribute))).AttributeName;
                    //leaf.Text = (new Attribute(getMostCommonValue(samples, targetAttribute))).AttributeName;
                    leaf.Text = getMostCommonValue(samples, targetAttribute).ToString() + "(" + value + ")"; 
                    temp.Nodes.Add(leaf);

                }
                else //��һ���� buildTree(samples, targetAttribute, attributes)���صĽڵ㵽�ڵ�N
                {
                    DTree_ID3 dc3 = new DTree_ID3();
                    TreeNode ChildNode = dc3.buildTree(aSample, targetAttribute, (Attribute[])aAttributes.ToArray(typeof(Attribute)), attributeSelectionMethod);
                    ChildNode.Text += "("+value+")";
                    //root.AddTreeNode(ChildNode, value);

                    //TreeNode leaf = new TreeNode();
                    //leaf.Text ="("+ value + ") "+ChildNode.attribute.AttributeName;
                    temp.Nodes.Add(ChildNode);
                }
            }
            roots = temp;
            return temp;
        }


        /// <summary>
        ///
        /// </summary>
        /// <param name="samples"></param>
        /// <param name="targetAttribute"></param>
        /// <returns></returns></returns?>
        public TreeNode mountTree(DataTable samples, string targetAttribute, Attribute[] attributes, string attributeSelectionMethod)
        {
            mSamples = samples;
            return buildTree(mSamples, targetAttribute, attributes, attributeSelectionMethod);
        }
    }
}