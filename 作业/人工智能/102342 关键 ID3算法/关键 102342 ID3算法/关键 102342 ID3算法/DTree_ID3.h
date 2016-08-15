using System;
using System::Collections::Generic;
using System::Text;
using System::Data;
using System::Collections;
using System::Windows::Forms;
namespace 关键102342ID3算法
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
        /// 判断样例集是否都属于同一类,是则返回此属性值，否则返回null
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
        ///// Retorna true caso todos os exemplos da amostragem s鉶 negativos
        ///// </summary>
        ///// <param name="samples">DataTable com as amostras</param>
        ///// <param name="targetAttribute">Atributo (coluna) da tabela a qual ser?verificado</param>
        ///// <returns>True caso todos os exemplos da amostragem s鉶 negativos</returns>
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

            //  if samples中的元组都是同一类C then
            string c = allSamplesSameClass(samples, targetAttribute);
            if ( c!=null)   //返回N作为叶节点，以类C标记
                return new TreeNode(new Attribute(c).AttributeName+c);
            

            //if attributes为空 then
            if (attributes.Length == 0) //返回N作为叶子节点，标记为D中的多数类；多数表决
                return new TreeNode(new Attribute(getMostCommonValue(samples, targetAttribute)).AttributeName);

            //计算目标属性的信息熵
            mTargetAttribute = targetAttribute;
            en.getEntropy(samples);

            //找出最好的分类属性，即信息熵最大的
            Attribute bestAttribute = getBestAttribute(samples, attributes, attributeSelectionMethod);

            //标记为节点root
            DTreeNode root = new DTreeNode(bestAttribute);
            temp.Text=bestAttribute.AttributeName;

            DataTable aSample = samples.Clone();

            //(10) 为bestAttribute的每个输出value划分元组并对每个划分产生子树
            foreach (string value in bestAttribute.values)
            {
                // Seleciona todas os elementos com o valor deste atributo				
                aSample.Rows.Clear();
                //aSample为满足输出value的集合，即一个划分（分支）
                DataRow[] rows = samples.Select(bestAttribute.AttributeName + " = " + "'" + value + "'");

                foreach (DataRow row in rows)
                {
                    aSample.Rows.Add(row.ItemArray);
                }

                //删除划分属性
                ArrayList aAttributes = new ArrayList(attributes.Length - 1);
                for (int i = 0; i < attributes.Length; i++)
                {
                    if (attributes[i].AttributeName != bestAttribute.AttributeName)
                        aAttributes.Add(attributes[i]);
                }


                //如果aSample为空，加一个树叶到节点N，标记为aSample中的多数类
                if (aSample.Rows.Count == 0)
                {
                    //return new TreeNode(new Attribute(getMostCommonValue(aSample, targetAttribute)).AttributeName);

                    TreeNode leaf = new TreeNode();
                    //leaf.Text = (new Attribute(getMostCommonValue(aSample, targetAttribute))).AttributeName;
                    //leaf.Text = (new Attribute(getMostCommonValue(samples, targetAttribute))).AttributeName;
                    leaf.Text = getMostCommonValue(samples, targetAttribute).ToString() + "(" + value + ")"; 
                    temp.Nodes.Add(leaf);

                }
                else //加一个由 buildTree(samples, targetAttribute, attributes)返回的节点到节点N
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