using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TaoMap
{
    class Program
    {
        static void Main(string[] args)
        {
            String[] lines = File.ReadAllLines("matrix.dat");
            int nRow = 0, nCol = 0;

            String[] values = lines[0].Split('\t');
            nRow = int.Parse(values[0]);
            nCol = int.Parse(values[1]);
            int tileWidth, tileHeight;
            values = lines[1].Split('\t');
            tileWidth = int.Parse(values[0]);
            tileHeight = int.Parse(values[1]);
            int nTileColumn = int.Parse(lines[2]);

            int[,] matrix = new int[nRow, nCol];

            for (int ir = 0; ir < nRow; ir++)
            {
                values = lines[ir + 3].Split('\t');
                for (int ic = 0; ic < nCol; ic++)
                {
                    matrix[ir, ic] = int.Parse(values[ic]);
                }
            }

            Image tilesheet = (Image)Image.FromFile("tilesheet.png").Clone();

            Image i = new Bitmap(nCol * tileWidth, nRow * tileHeight);
            Graphics g = Graphics.FromImage(i);

            for (int ir = 0; ir < nRow; ir++)
            {
                for (int ic = 0; ic < nCol; ic++)
                {
                    int value = matrix[ir, ic];
                    Rectangle cropRect = new Rectangle()
                    {
                        X = tileWidth * (value % nTileColumn),
                        Y = tileHeight * (value / nTileColumn),
                        Width = tileWidth,
                        Height = tileHeight
                    };

                    g.DrawImage(tilesheet, new Rectangle(ic * tileWidth, ir * tileHeight, tileWidth, tileHeight),
                        cropRect, GraphicsUnit.Pixel
                        );
                }
            }

            i.Save("out.png");
            Console.ReadKey();
        }
    }
}
